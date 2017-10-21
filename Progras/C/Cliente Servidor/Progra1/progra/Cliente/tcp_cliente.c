#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

struct request {
    int Client_Socket;
    char* Archivo;
};

void gotoxy(int x,int y)
 {
 printf("%c[%d;%df",0x1B,y,x);
 }

void* Solicitar(void *arguments)
{
    //Definicion de variables. 
    int bytesReceived = 0;
    char recvBuff[1024];
    char request[4096] = "GET /";
    memset(recvBuff, '0', sizeof(recvBuff));
    struct request *Sol = (struct request *)arguments;

    //prints 

    printf("NumClientSocket= %d\n", Sol -> Client_Socket);

    strcat(request,Sol->Archivo);
    strcat(request," Cliente");

    printf("Se pide al server %s\n", request);
    
    send(Sol->Client_Socket,request,sizeof(request),0);
    
    /* Create file where data will be stored */
    
    FILE *fp;
    printf("File Name: %s\n",Sol -> Archivo);
    printf("Receiving file...");
      fp = fopen(Sol -> Archivo, "ab"); 
     if(NULL == fp)
     {
          printf("Error opening file");
         return 1;
     }
    long double sz=1;
    /* Receive data in chunks of 256 bytes */
    while((bytesReceived = read(Sol->Client_Socket, recvBuff, 1024)) > 0)
    { 
        sz++;
        gotoxy(0,4);
        printf("Received: %llf Mb",(sz/1024));
       fflush(stdout);
        // recvBuff[n] = 0;
        fwrite(recvBuff, 1,bytesReceived,fp);
        // printf("%s \n", recvBuff);
    }

    printf("\nFile OK....Completed\n");



    printf("Closing Connection for id: %d\n",Sol -> Client_Socket);
    close(Sol -> Client_Socket);
    shutdown(Sol -> Client_Socket,SHUT_WR);
    pthread_exit(NULL);
    sleep(2);
     
}



int main(int argc)
{
    

    
    system("clear");
    struct sockaddr_in serv_addr;
    int sockfd = 0;
    printf("Preparando....\n" );


    /* Create a socket first */
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }  
    printf("Creacion del socket exitosa \n" );

    /* Initialize sockaddr_in data structure */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9030); // port
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    
    printf("Conectandose al sever ....\n");

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
        printf("\n Error : No se pudo conectar \n");
        return 1;
    }

    else
    {
        printf("Conxion al server exitosa...\n" );
    }


       char str[300];
       char *word;
       printf( "Ingrese los archivos a solcitar :");
       gets( str );

        printf("Archivos : %s\n", str);
        
        word = strtok(str, ";");
        int server_thread_status;
        struct request Sol; 
        Sol.Client_Socket= sockfd; 

        while(word!=NULL)
        {
            
            
            Sol.Archivo=word;
            printf( "Solicitando Archivo:%s....\n",Sol.Archivo);

            pthread_t server_thread;
            server_thread_status = pthread_create (&server_thread, NULL, &Solicitar,  (void *) &Sol);
            sleep(2);
            word= strtok(NULL, "/");


        }
        











 //    char request[4096] = "GET /";
 //    strcat(request,Sol->Archivo);
 //    strcat(request," Cliente");

 //    printf("Se pide al server %s\n", request);
    
 //    send(Sol->Client_Socket,request,sizeof(request),0);
   	
 //    /* Create file where data will be stored */
    
 //    FILE *fp;
	// printf("File Name: %s\n",word);
	// printf("Receiving file...");
 //   	 fp = fopen(word, "ab"); 
 //    	if(NULL == fp)
 //    	{
 //       	 printf("Error opening file");
 //         return 1;
 //    	}
 //    long double sz=1;
 //    /* Receive data in chunks of 256 bytes */
 //    while((bytesReceived = read(Sol->Client_Socket, recvBuff, 1024)) > 0)
 //    { 
 //        sz++;
 //        gotoxy(0,4);
 //        printf("Received: %llf Mb",(sz/1024));
	//    fflush(stdout);
 //        // recvBuff[n] = 0;
 //        fwrite(recvBuff, 1,bytesReceived,fp);
 //        // printf("%s \n", recvBuff);
 //    }

 //    printf("\nFile OK....Completed\n");

    return 0;
}
