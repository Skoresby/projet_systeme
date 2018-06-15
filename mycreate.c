#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mycreate.h"
#include "path.h"

extern Inode *INODE;
extern VE VAR_E;


int mycreate(char *fichier,mode_t mode)
{
	int fd =-1, ninode;
	Path recup =path(fichier,3);
	
	ninode=verifExistence(recup);
	printf("le chemein est %s \n",recup.chemin);
	fd=myopen(ninode);
	
	if(fd==-1)
	{
		perror("open");
		return fd;
	}
	
	fd=myclose(fd);
	if(fd==-1 || fd==-2)
	{
		perror("close");
		return fd;
	}
	
	if(VAR_E.nbNinode==0)//tableau vide
    {
		INODE=(Inode*)malloc(sizeof(Inode));
		VAR_E.nbNinode+=1;
		memcpy(INODE[0].nom_fichier,fichier,strlen(fichier)+1);
		INODE[0].permissions=mode;
		INODE[0].etat=-1;
		time_t t =time(NULL);
		char *tt=ctime(&t);
		memcpy(INODE[0].d_last_mod,tt,strlen(tt)+1);
		INODE[0].type='f';
		INODE[0].taille=1;
		char propr[]="isty";
		memcpy(INODE[0].n_pro,propr,strlen(propr)+1);
		INODE[0].nb_lien=1;
	}
	else
     {
		VAR_E.nbNinode+=1;
		Inode* tmp=(Inode*)malloc(VAR_E.nbNinode*sizeof(Inode));
		int i;
		for(i=0;i<VAR_E.nbNinode-1;i++)
		{
			
			tmp[i]=INODE[i];
		}
		INODE=NULL;
		INODE=(Inode*)malloc(VAR_E.nbNinode*sizeof(Inode));
		for(i=0;i<VAR_E.nbNinode;i++)
		{
			
			INODE[i]=tmp[i];
		}
		tmp=NULL;
		memcpy(INODE[VAR_E.nbNinode-1].nom_fichier,fichier,strlen(fichier)+1);
		INODE[VAR_E.nbNinode-1].permissions=mode;
		INODE[VAR_E.nbNinode-1].etat=-1;
		time_t t =time(NULL);
		char *tt=ctime(&t);
		memcpy(INODE[VAR_E.nbNinode-1].d_last_mod,tt,strlen(tt)+1);
		INODE[VAR_E.nbNinode-1].type='f';
		INODE[VAR_E.nbNinode-1].taille=1;
		char propr[]="isty";
		memcpy(INODE[VAR_E.nbNinode-1].n_pro,propr,strlen(propr)+1);
		INODE[VAR_E.nbNinode-1].nb_lien=1;
	}
	int ninodePath=verifExistence(VAR_E.mypath);
	mywrite(ninodePath, INODE[0].nom_fichier, sizeof(INODE[0].nom_fichier));//on écrit dans le fichier du répertoire le nom du fichier créé
	return fd;

}

