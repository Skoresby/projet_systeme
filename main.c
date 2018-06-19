#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variable_environnement.h"
#include "inode.h"

VE VAR_E;
Inode* INODE;

int main()
{
	char** parametre;
	char recup[100];
	char* recup2;
	char command[100];
	char* test;
	
	printf("%s$ ", VAR_E.mypath);
	fgets(recup, sizeof(recup),stdin);
	recup2=(char*)malloc(strlen(recup)*sizeof(char));

	strcat(recup2, recup);
	test = strtok(recup," ");
	
	strcpy(command, "./" );
	strcat(command, recup2 );
	
	if( strcmp(test,"touch")==0){
		printf("1.cmd system avec tableau\n");
		printf("command %s\n",command);
		system(command);
	}
	else if( strcmp(test,"ls")==0){
		printf("2.cmd system avec tableau\n");
		printf("command %s\n",command);
		system(command);
	}
	else if( strcmp(test,"cat")==0){
		 printf("3.cmd system avec tableau\n");
		 printf("command %s\n",command);
		system(command);
	}
	else if( strcmp(test,"echo")==0){
		 printf("4.cmd system avec tableau\n");
		 printf("command %s\n",command);
			system(command);
	}
	else if( strcmp(test,"ls")==0){
		printf("5.cmd system avec tableau\n");
		printf("command %s\n",command);
		system(command);
	}
	else if( strcmp(test,"mkdir")==0){
		printf("6.cmd system avec tableau\n");
		printf("command %s\n",command);
		system(command);
	}
	else if( strcmp(test,"mv")==0){
		printf("7.cmd system avec tableau\n");
		printf("command %s\n",command);
		system(command);
	}
	else if( strcmp(test,"df")==0){
		printf("8.cmd system avec tableau\n");
		printf("command %s\n",command);
		system(command);
	}
	else if( strcmp(test,"rm")==0){
		printf("9.cmd system avec tableau\n");
		printf("command %s\n",command);
		system(command);
	}
	else if( strcmp(test,"cd")==0){
		printf("10.cmd system avec tableau\n");
		printf("command %s\n",command);
		system(command);
	}
	else
		printf("La commande n'existe pas\n");
	
	//maj_fichier();
	
	
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




