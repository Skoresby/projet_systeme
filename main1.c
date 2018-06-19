#include <stdlib.h>
#include <stdio.h>
#include "variable_environnement.h"
#include "inode.h"
#include "vg.h"
#include "liste_chainee.h"
extern Inode* INODE;
extern VE VAR_E;

int main()
{
	char quit;
	
	INODE=	(Inode*)malloc(10*sizeof(Inode));
	VAR_E.mypath[0]='/'; /*faire une fonction pour le remplir*/
	VAR_E.nbNinode=0;
	VAR_E.nbBloc=0;
	
	system("gcc main.c -o main");
	system("gcc mainClose.c myclose.c -o close");
	system("gcc mainOpen.c myopen.c -o open");
	system("gcc mainRead.c myread.c myopen.c myclose.c -o read");
	system("gcc mainWrite.c mywrite.c myopen.c myclose.c liste_chainee.c -o write");
	system("gcc mainCreate.c mycreate.c myopen.c myclose.c mywrite.c liste_chainee.c verifExistence.c path.c -o create");
	system("gcc mainMkdir.c mkdir.c mycreate.c -o mkdir");
	/*system("gcc mainPath.c path.c -o path");*/
	system("gcc -Wall mainLn.c ln.c path.c verifExistence.c verifType.c link.c -o ln ");
	system("gcc mainUnLink.c unlink.c path.c verifExistence.c liste_chainee.c -o unlink");
	system("gcc mainLs.c ls.c verifExistence.c verifType.c myread.c -o ls");
	system("gcc mainRmdir.c rmdir.c unlink.c -o rmdir");

	do
	{
		system("./main");
		printf("Voulez vous quittez? oui:1 non:autre : \n");
		scanf("%c",&quit);
	}while(quit !='1'); 
	
	return 0;
}
