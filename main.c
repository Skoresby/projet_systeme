#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variable_environnement.h"
#include "inode.h"

VE VAR_E;

int main(int argc, char *argv[])
{
	//faire tous les gcc
	//~ Inode tabInode[3] ={ {"-rwx_wxrwx","/tac/much/","Lynda.csv","2017-08-12",1,'f',2,3,4757,"HUGO",-1,2,"ETU",NULL},
					 //~ {"drwx_wxr_x","/bin/fich/","file.txt","2015-02-02",1,'d',1,3,8572,"BART",-1,1,"ETU",NULL},
					 //~ {"-rwx_wxrwx","/Dossier/FICHIER/","newrep/","2009-04-02",1,'f',2,3,4388,"Arry",-1,2,"ETU",NULL}};
	char quit='q';				 
	VAR_E.mypath[0]='/'; //faire une fonction pour le remplir
	VAR_E.nbNinode=0;
	VAR_E.nbBloc=0;
	char *test=argv[1];
	printf("agrv :%sc\n",test);
	do
	{
		printf("%s$ ", VAR_E.mypath);
		if( strcmp(argv[1],"touch")==0)
				printf("cmd system avec tableau\n");
		else if( strcmp(argv[1],"ls")==0)
			printf("cmd system avec tableau\n");
		else if( strcmp(argv[1],"cat")==0)
			 printf("cmd system avec tableau\n");
		else if( strcmp(argv[1],"echo >")==0)
			 printf("cmd system avec tableau\n");
		else if( strcmp(argv[1],"ls")==0)
			printf("cmd system avec tableau\n");
		else if( strcmp(argv[1],"mv")==0)
			printf("cmd system avec tableau\n");
		else if( strcmp(argv[1],"mv")==0)
			printf("cmd system avec tableau\n");
		else if( strcmp(argv[1],"df")==0)
			printf("cmd system avec tableau\n");
		else if( strcmp(argv[1],"rm")==0)
			printf("cmd system avec tableau\n");
		else if( strcmp(argv[1],"cd")==0)
			printf("cmd system avec tableau\n");
		else
			printf("La commande n'existe pas\n");

		maj_fichier();
		printf("Voulez vous quittez? oui:1 non:autre\n");
		scanf("%c",&quit);
	}while(quit !='1');
	
	void maj_fichier()
	{
		int fd=open("disque.txt", O_RDWR);
		
		if(fd>0)
		{
			//deplace le curseur de 100-nb octet ecrit
			close(fd);
		}
		else
		{
			printf("ERREUR OUVERTURE FICHIER\n");
		}
		
		
	}
}
