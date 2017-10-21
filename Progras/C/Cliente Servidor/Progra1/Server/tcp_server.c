#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>



struct sockaddr_in c_addr;
char fname[100];

void* SendFileToClient(int *arg)
{
    int connfd=(int)*arg;
    printf("Connection accepted and id: %d\n",connfd);
    printf("Connected to Clent: %s:%d\n",inet_ntoa(c_addr.sin_addr),ntohs(c_addr.sin_port));



    FILE *fp = fopen(fname,"rb");
    
    if(fp==NULL)
    {
        printf("File open error");
        return 1;   
    }   

    /* Read data from file and send it */
    while(1)
    {
        /* First read file in chunks of 256 bytes */
        unsigned char buff[1024]={0};
        int nread = fread(buff,1,1024,fp);
        
        printf("Bytes read %d \n", buff);        

        /* If read was success, send data. */
        if(nread > 0)
        {
            printf("Sending \n");
            write(connfd, buff, nread);
        }
        if (nread < 1024)
        {   
            if (feof(fp))
            {
                printf("End of file\n");
	            printf("File transfer completed for id: %d\n",connfd);
	        }
            if (ferror(fp))
                printf("Error reading\n");
            break;
        }
    }
    
    printf("Closing Connection for id: %d\n",connfd);
    close(connfd);
    shutdown(connfd,SHUT_WR);
    sleep(2);
}




int main()
{
	//char server_message[255]= "Llego al server";

	//Abrir el archivo para el server

	FILE *file; 
	pthread_t tid; 
	size_t clen=0;

	// Se crea el socket
	int server_socket,err; 

	server_socket= socket(AF_INET, SOCK_STREAM, 0);

	//Specificar la direccion 
	struct sockaddr_in server_address;
	server_address.sin_family= AF_INET;
	server_address.sin_port = htons(9002); // se pasa el puerto para convertir el dato al formato correcto 
	server_address.sin_addr.s_addr = INADDR_ANY;

	//agregar la peticion al socket  
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));


	listen(server_socket, 5); 

	int client_socket,read_size ;
	char *client_message[2000];
	
	while(1)
	{
		char* word;
    	char response_data[1024];

    	clen=sizeof(c_addr);
		client_socket=  accept(server_socket, (struct sockaddr*)&c_addr,&clen); // Acepta el cliente 

		recv(client_socket , client_message , 2000 , 0); 
    	
    	word = strtok(client_message, "/");
		word = strtok(NULL, "/");
		word = strtok(NULL, "/");
		word = strtok(NULL, "/");
		strcpy(fname,word);
		printf("Archivo a enviar %s\n", fname);


		// printf("Archivo: %s\n", word);
		// file=fopen(word, "r" );
		// fgets(response_data, 1024, file);

        //Send the message back to client
        //send(client_socket, response_data, sizeof(response_datas), 0 );


        if(client_socket<0)
        {
		  printf("Error in accept\n");
		  continue;	
		}
	        err = pthread_create(&tid, NULL, &SendFileToClient, &client_socket); 
	        
	        if (err != 0)
	            printf("\ncan't create thread :[%s]", strerror(err));

	}

	// Cerrar el socket
	close(server_socket);	
	
	return 0; 
}