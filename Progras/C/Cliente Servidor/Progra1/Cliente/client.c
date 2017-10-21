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


void gotoxy(int x,int y)
 {
 printf("%c[%d;%df",0x1B,y,x);
 }

int main(int argc, char *argv[])
{
    
    char *address;
    char* word;

    system("clear");
    int sockfd = 0;
    int bytesReceived = 0;
    char recvBuff[1024];
    memset(recvBuff, '0', sizeof(recvBuff));


    address = argv[1];
    printf("La direccion es : %s\n", address);
    

    word = strtok(address, "/");
    word = strtok(NULL, "/");
    printf("Archivo: %s\n", word);



    struct sockaddr_in serv_addr;

    /* Create a socket first */
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }

    /* Initialize sockaddr_in data structure */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9002); // port
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    /* Attempt a connection */
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
        printf("\n Error : Connect Failed \n");
        return 1;
    }


    printf("Connected to ip: %s : %d\n",inet_ntoa(serv_addr.sin_addr),ntohs(serv_addr.sin_port));

    char request[4096] = "GET / ";
    strcat(request,word);
    strcat(request," HTTP/1.1/\n Cliente");
     
    send(sockfd,request,sizeof(request),0);
    
    printf("Se pide al server %s\n", request);

   	 /* Create file where data will be stored */
    FILE *fp;

	//strcat(fname,"AK");
	printf("File Name: %s\n",word);
	printf("Receiving file...");
   	 fp = fopen(word, "ab"); 
    	if(NULL == fp)
    	{
       	 printf("Error opening file");
         return 1;
    	}
    long double sz=1;
    /* Receive data in chunks of 256 bytes */
    while((bytesReceived = read(sockfd, recvBuff, 1024)) > 0)
    { 
        sz++;
        gotoxy(0,4);
        printf("Received: %llf Mb",(sz/1024));
	   fflush(stdout);
        // recvBuff[n] = 0;
        fwrite(recvBuff, 1,bytesReceived,fp);
        // printf("%s \n", recvBuff);
    }

    if(bytesReceived < 0)
    {
        printf("\n Read Error \n");
    }
    printf("\nFile OK....Completed\n");
    return 0;
}
