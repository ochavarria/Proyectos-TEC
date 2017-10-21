#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>
#include <time.h>


/*-------------------------------------Linked List for a single char--------------------------------------------------*/
char ER[50]; 
char txt[255];
char abc[50];
int canthileras;
int hilerasG;
int Verificador(char* palabra){
        regex_t regex;
        int reti;
        char msgbuf[100];

        reti = regcomp(&regex, ER, 0);
        if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }

        reti = regexec(&regex, palabra, 0, NULL, 0);
        if( !reti ){
                puts("Hilera Reconocida");
                return 0;
        }
        else if( reti == REG_NOMATCH ){
                puts("Hilera No Reconocida");
                return 1;
        }
        else{
                regerror(reti, &regex, msgbuf, sizeof(msgbuf));
                fprintf(stderr, "Regex match failed: %s\n", msgbuf);
                exit(1);
        }

	regfree(&regex);

        return 0;
}
int Verificadorbool(char* palabra){
        regex_t regex;
        int reti;
        char msgbuf[100];

        reti = regcomp(&regex, ER, 0);
        if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }

        reti = regexec(&regex, palabra, 0, NULL, 0);
        if( !reti ){
        		hilerasG+=1;
                return 0;
        }
        else if( reti == REG_NOMATCH ){
                return 1;
        }

	regfree(&regex);

        return 0;
}
void cambio(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permutaciones(char *stri, int inicio, int largo)
{
   int i;
   if (inicio == largo)
   	{
   		if(Verificadorbool(stri)==0)
     	{printf("%s\n", stri);}
 	}
   else
   {
       for (i = inicio; i <= largo && hilerasG<canthileras; i++)
       {
          cambio((stri+inicio), (stri+i));
          permutaciones(stri, inicio+1, largo);
          cambio((stri+inicio), (stri+i)); 

       }
   }
}

void readExpresion(const char *fileName){
	FILE *ptrFile;
	ptrFile=fopen(fileName,"r");
	
	char expresion[50];
	fgets(expresion, 255, (FILE*)ptrFile);
   	strcpy(ER,expresion);

	}
void readText(const char *fileName){
	FILE *ptrFile;
	ptrFile=fopen(fileName,"r");
	
	char Text[255];
	fgets(Text, 255, (FILE*)ptrFile);
   	strcpy(txt,Text);

	}
void readAbc(const char *fileName){
	FILE *ptrFile;
	ptrFile=fopen(fileName,"r");
	
	char Text[50];
	fgets(Text, 50, (FILE*)ptrFile);
   	strcpy(abc,Text);

	}
void Generador(int mod)
{
		int despl=mod ;
		int cont = 1;

		char* someString = abc;
		int len = strlen(abc);
		
		

		printf("Generaciones\n");
		int iterador=len;

		while (despl<len&&despl<canthileras)
		{
			 
			char* otherString = 0;
			
			while(cont<=iterador&& cont<canthileras){

				
				
				otherString = (char*) malloc(cont+1);
				strncpy(otherString,&someString[despl],cont);
     
		
				 
				otherString[cont] = 0;
				
				int n = strlen(otherString);

    			permutaciones(otherString, 0, n-1);
		

				cont+=1;
				memset(otherString,0,cont);
			}
			iterador-=1;
			cont =1;
			despl+=1;

			

		}
}
int main(){
	char op[2]; 

	char abecedario[50];
	char RutaER[50];

	printf("AutoER\n**Menu**\n");

	printf("Ingrese ruta del archivo con el abecedario\n");
	scanf("%s",abecedario);

	readAbc(abecedario);
	printf("%s\n", abc);

	printf("Ingrese la ruta del ER inicial\n");
	scanf("%s",RutaER);

	readExpresion(RutaER);
	printf("%s\n", ER);

	printf("Elija:\n1-Generador de Hileras\n2-Buscador de Hleras\n");

	printf("Digite su Opcion ");
	scanf("%s",op);


	if((strcmp(op, "1") == 0))
	{
		printf("\n");
		printf("\n");
		printf("Modo Generador de Hileras\n");
		
		char mod[2]; 

		printf("Ingrese la cantidad maxima de hileras a generar ");
		scanf("%d",&canthileras);
		
		printf("Elija:\n1-Generador Ordenado\n2-Generador Aleatorio\n");
		scanf("%s",mod);

		if((strcmp(mod, "1") == 0))
		{
			printf("Modo Ordenado\n");
			Generador(0);
		}
		else
		{
			if((strcmp(mod, "2") == 0))
			{
				Generador(1);

			}
			else
			{
				printf("Error!!");
			}

		}		

		
	}
	else if((strcmp(op, "2") == 0))
	{
		printf("\n");
		printf("\n");
		char Rutatexto[50];
		printf("Modo Buscador de Hileras\n");
		printf("Ingrese ruta del archivo a procesar \n");
		scanf("%s",Rutatexto);
		readText(Rutatexto);
		printf("%s\n", txt);
		strtok(txt,"\n");
		//Verificador("Ac");
		clock_t t;
		t=clock();

		
		
		int despl=0 ;
		int cont = 1;

		char* someString = txt;
		int len = strlen(txt);
		
		

		printf("%d", len);
		printf("%s\n","");

		printf("Substrings\n");
		int iterador=len;

		while (despl<len)
		{
			 
			char* otherString = 0;
			
			while(cont<=iterador){

				
				
				otherString = (char*) malloc(cont+1);
				strncpy(otherString,&someString[despl],cont);
     
		
				 
				otherString[cont] = 0;
				puts("-------------------------------------------------------------------------------\n");
				printf("%s\n", otherString);

				Verificador(otherString);

				cont+=1;
				memset(otherString,0,cont);
			}
			iterador-=1;
			cont =1;
			despl+=1;

			

		}	
	printf("\n");
	t = clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("(Tomó %f segundos en ejecutarse)\n",time_taken );
	printf("\n");
	}	
	else
	{
		printf("Error!!");
	}

	printf("\n");
	printf("\n");
	
}