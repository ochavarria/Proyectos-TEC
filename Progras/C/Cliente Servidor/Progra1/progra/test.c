
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>


int main(){
	FILE *filedata;
	filedata = fopen("a.jpg", "rb");

	long fSize;

	char *httpheader;
	if(filedata == NULL){
		printf("Error al abrir el archivo \n");
		sprintf(httpheader, "HTTP/1.1 200 OK\r\n"
						"Content-Type: text/html\r\n\n");
		strcat(httpheader,"<html><body><h1>Error 404</h1><p>Recurso no encontrado, asegurese de haber escrito el nombre del archivo bien</p></body></html>");
		
	}
	else{
		//carga el archivo en memoria
		fseek (filedata , 0 , SEEK_END);
		fSize = ftell (filedata);
		rewind (filedata);

		
		char *htmldata = malloc(fSize + 1);
		fread (htmldata,fSize,1,filedata);
		 
		// terminate
		fclose (filedata);
		//add header
		char *httpheader = malloc(fSize + 200);

		sprintf(httpheader, "HTTP/1.1 200 OK\n"
						"Content-Type: image/jpeg\n"
						"Content-Length: %i\n"
						"Accept-Ranges: bytes\n"
        				"\n" ,fSize);

		//strcat(httpheader,htmldata); doesnt work for images


		memcpy(httpheader+strlen(httpheader),htmldata,fSize);
		printf("DEBUG\n");
}
return 0; }