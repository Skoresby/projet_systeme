#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variable_environnement.h"
#include "inode.h"
#include "liste_chainee.h"
VE VAR_E;
Inode* INODE;

int main()
{
	//char** parametre;
	char recup[100];
	char* recup2;
	char command[100];
	char **test;
	char * rep;
	int i=0;
	char*p=NULL;

	do
	{
		i=0;
		printf("%s$ ", VAR_E.mypath);
		fgets(recup, sizeof(recup),stdin);

		recup2=(char*)malloc(strlen(recup)*sizeof(char));
		strncat(recup2, recup, strlen(recup)-1);//on enleve le retour a la ligne
		
		test=(char**)malloc(100*sizeof(char*));//tableau contenant les reponses de l utilisateur selon les espaces ("ls -l" enregistre "ls" et "-l" )
		
		p = strtok(recup2, " ");//p est un pointeur sur la chaine contenant l argument i
		while(p != NULL)
		{
		  
			if(i < 100)
			{
				test[i] = malloc(sizeof(char) * (1+strlen(p)));
				strcpy(test[i], p);
				i++;
			}
			else
				break;
			
			p = strtok(NULL, " ");//on continue de séparer en pointant sur NULL, le dernier caractere enregistre de la chaine deja separee
		}

		strcpy(command, "./" );
		strcat(command, recup2 );
		

		if( strcmp(test[0],"touch")==0){
			printf("1.cmd system avec tableau\n");
			printf("command %s\n",command);
			system(command);
		}
		else if( strcmp(test[0],"ls")==0){
			printf("2.cmd system avec tableau\n");
			printf("command %s\n",command);
			system(command);
		}
		else if( strcmp(test[0],"cat")==0){
			 printf("3.cmd system avec tableau\n");
			 printf("command %s\n",command);
			system(command);
		}
		else if( strcmp(test[0],"echo")==0){
			 printf("4.cmd system avec tableau\n");
			 printf("command %s\n",command);
				system(command);
		}
		else if( strcmp(test[0],"mkdir")==0){
			printf("5.cmd system avec tableau\n");
			printf("command %s\n",command);
			system(command);
		}
		else if( strcmp(test[0],"mv")==0){
			printf("6.cmd system avec tableau\n");
			printf("command %s\n",command);
			system(command);
		}
		else if( strcmp(test[0],"df")==0){
			printf("7.cmd system avec tableau\n");
			printf("command %s\n",command);
			system(command);
		}
		else if( strcmp(test[0],"rm")==0){
			printf("8.cmd system avec tableau\n");
			printf("command %s\n",command);
			system(command);
		}
		else if( strcmp(test[0],"cd")==0){
			printf("9.cmd system avec tableau\n");
			printf("command %s\n",command);
			system(command);
		}
		else if( strcmp(test[0],"exit")==0)
			printf("vous quittez le terminal.\n");
		
		else
			printf("La commande n'existe pas\n");
		
		//maj_fichier();
		
		//on libere l espace alloue
		rep=(char*)malloc(strlen(test[0])*sizeof(char));
		strcat(rep, test[0]);
		for(i=0; i<100; i++)
		{
			free(test[i]);
		}
		free(test);
		free(p);
		free(recup2);
		
	}while(strcmp(rep,"exit")!=0);
	
	free(rep);
	
	return 0;
}
/*
//~ void maj_fichier()
	//~ {
		//~ int fd=open("disque.txt", O_RDWR);
		
		//~ if(fd>0)
		//~ {
			//~ //deplace le curseur de 100-nb octet ecrit
			//~ close(fd);
		//~ }
		//~ else
		//~ {
			//~ printf("ERREUR OUVERTURE FICHIER\n");
		//~ }
		
		
	//~ } */




