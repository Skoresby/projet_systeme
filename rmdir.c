#include "rmdir.h"
#include "path.h"
#include "myread.h"
#include "verifExistence.h"
#include "vg.h"
#include "liste_chainee.h"
extern Inode* INODE;


void myrmdir(char * rep)
{
	char buffer[1000]="";
	if(rep[strlen(rep)-1]=='/')
		strncpy(rep, rep,strlen(rep)-1);//on enleve le '/' de la fin
	Path repPath=path(rep, 3);
	int ninodeRep=verifExistence(repPath);
	if(ninodeRep==-1)
	{
		printf("erreur fichier non trouvé\n");
		exit(EXIT_FAILURE);
	}
	myread(ninodeRep, buffer, sizeof(buffer));
	
	if(buffer!=NULL)
	{
		printf("le répertoire n'est pas vide, on ne peut le supprimer\n");
		exit(EXIT_FAILURE);
	}
	//on change le type de rep, comme il est vide, en fichier, afin de pouvoir utiliser unlink
	INODE[ninodeRep].type=0;
	char*nom=(char*)malloc((strlen(repPath.nom)+strlen(repPath.chemin))*sizeof(char));//si jamais un choix a du etre fait dans path, il faut que l'uilisateur doive le refaire
	strcpy(nom, repPath.chemin);
	strcat(nom, repPath.nom);
	unlink(nom);
}
