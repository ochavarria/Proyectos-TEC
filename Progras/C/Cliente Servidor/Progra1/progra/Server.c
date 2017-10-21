#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int strEnd(const char *s, const char *end){
	size_t ls = strlen(s);
	size_t lt = strlen(end);
	if(ls >= lt){
		return (0 == memcmp(end,s+(ls-lt),lt));
	}
	return 0;
}

int main(){
	FILE *filedata;
	long fSize;
	int browserBool;

	///definicion socket
	int serversocket;
	serversocket = socket(AF_INET, SOCK_STREAM, 0);

	//address
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9030); // port
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    //bind
	bind(serversocket,(struct sockaddr *)&serv_addr, sizeof(serv_addr));
    
	//listen
	listen(serversocket, 10);

	int clientsocket;
	char respuesta[4096];
    char buffer[1024];
    char ContentType[25];

    //lee nombre de archivo por medio del GET
    int charcount=5;
    int buffercount=0;

	while(1){
		printf("DEBUG\n");
	//conexion al client

	clientsocket = accept(serversocket, NULL,NULL);

	//recibe el GET
	recv(clientsocket,&respuesta, sizeof(respuesta), 0);

    //lee el nombre del archivo
    while(respuesta[charcount] != 32 ){
    	buffer[buffercount] = respuesta[charcount];
    	charcount++;
    	buffercount++;
    }
    if(respuesta[charcount+1] == 67){
    	printf("ES EL CLIENTE archivo: %s",buffer);
    	browserBool = 0;
    	printf("browserBool: %i",browserBool);
    }
    else{
    	printf("ES EL BROWSER\n");
    	browserBool = 1;
    	printf("browserBool: %i",browserBool);
    }
    charcount=5;
    buffercount=0;
    if(browserBool == 1)
    {
	    //si no se especifica manda la pagina de inicio
	    if(buffer[0] == '\0'){
	    	strcpy(buffer,"Inicio.html");
	    }
	    //dependiendo del tipo de archivo cambiamos el ContentType del header
	    if(strEnd(buffer,".txt")){
	    	strcpy(ContentType,"text/plain");
	    }
	    else if(strEnd(buffer,".html")){
	    	strcpy(ContentType,"text/html");
	    }
	    else if(strEnd(buffer,".png")){
	    	strcpy(ContentType,"image/png");
	    }
	    else if(strEnd(buffer,".jpg")){
	    	strcpy(ContentType,"image/jpeg");
	    }
	    else if(strEnd(buffer,".jpeg")){
	    	strcpy(ContentType,"image/jpeg");
	    }
	    else if(strEnd(buffer,".gif")){
	    	strcpy(ContentType,"image/gif");
	    }
	    else{
	    	strcpy(ContentType,"text/plain");
	    }

	    //intenta abrir el archivo
	    filedata = fopen(buffer, "rb");
		memset(buffer,0,sizeof(buffer));
		
		if(filedata == NULL){
			printf("Error al abrir el archivo \n");
			
			char *mensaje = malloc(200);
			sprintf(mensaje, "HTTP/1.1 200 OK\r\n"
							"Content-Type: text/html\r\n\n");
			strcat(mensaje,"<html><body><h1>Error 404</h1><p>Recurso no encontrado, asegurese de haber escrito el nombre del archivo bien</p></body></html>");
			send(clientsocket,mensaje,strlen(mensaje),0);
		}
		else{
			//carga el archivo en memoria


			fseek (filedata , 0 , SEEK_END);
			fSize = ftell (filedata);
			rewind (filedata);

			//guarda los datos del archivo
			char *htmldata = malloc(fSize + 1);
			 fread (htmldata,fSize,1,filedata);
			 
			// terminate
			fclose (filedata);
			
			//inicializa el tamano del mensaje a enviar con el tamano del archivo + 150 para el header HTTP
			char *mensaje = malloc(fSize + 150);
			sprintf(mensaje, "HTTP/1.1 200 OK\n"
							"Content-Type: %s\n"
							"Content-Length: %i\n"
							"Accept-Ranges: bytes\n"
	        				"\n",ContentType ,fSize);

			//strcat(mensaje,htmldata); doesnt work for images

			memcpy(mensaje+strlen(mensaje),htmldata,fSize);

			//printf("%s\n",mensaje);
			send(clientsocket,mensaje,strlen(mensaje)+fSize,0);
			memset(mensaje,0,sizeof(mensaje));
			close(clientsocket);
		    shutdown(clientsocket,SHUT_WR);
		}
	}
	if(browserBool == 0){
		printf("entro al else\n");

	  	  //intenta abrir el archivo
	     	filedata = fopen(buffer, "rb");
			memset(buffer,0,sizeof(buffer));
		    
		    if(filedata==NULL)
		    {
		        printf("File open error");
		        fclose (filedata);

			  	printf("Closing Connection for id: %d\n",clientsocket);
			    close(clientsocket);
			    shutdown(clientsocket,SHUT_WR);
		        break;   
		    }   

		    /* Read data from file and send it */
		    while(1)
		    {
		        /* First read file in chunks of 256 bytes */
		        unsigned char buff[1024]={0};
		        int nread = fread(buff,1,1024,filedata);
		        
		        printf("Bytes read %d \n", buff);        

		        /* If read was success, send data. */
		        if(nread > 0)
		        {
		            printf("Sending \n");
		            write(clientsocket, buff, nread);
		        }
		        if (nread < 1024)
		        {   
		            if (feof(filedata))
		            {
		                printf("End of file\n");
			            printf("File transfer completed for id: %d\n",clientsocket);
			        }
		            if (ferror(filedata))
		                printf("Error reading\n");
		            break;
		    	}
		  	}

			// terminate
			fclose (filedata);

		  	printf("Closing Connection for id: %d\n",clientsocket);
		    close(clientsocket);
		    shutdown(clientsocket,SHUT_WR);
		    sleep(2);
		}
    }

    //cerrar socket
    close(serversocket);
	return 0;
}