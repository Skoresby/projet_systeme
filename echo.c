#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variable_environnement.h"
#include "inode.h"
#include "vg.h"
#include "path.h"
#include "verifExistence.h"
#include "mycreate.h"
#include "myopen.h"
#include "mywrite.h"
#include "myclose.h"

extern Inode *INODE;
extern VE VAR_E;

void myecho(int etat, char *chaine);

int main(int argc,char *argv[])
{
	//le premier argument est forcement le fichier
   
    char tab[100]="";
    int i;
// on concaterne tout les arguments passé en paremetre à partir de
//argv[2]( pour ne pas recuperer le nom du fichier)
// et on stock dans un tableau une dimension
    for(i=2;i<argc;i++)
    {
		  strcat(tab , argv[i]);
        strcat(tab ," ");//espacer les mots de la chaine à redictionner dans
 //fichier

    }
       
	//on recupere le chemin du fichier
	Path tmp=path(argv[1], 3);
	
    int ninode=verifExistence(tmp);
    if(ninode==-1)//si le fichier n existe pas
    {
		if(mycreate(argv[1], 2)==-1)
      {
         printf("probleme lors de la creation du fichier\n");
         exit(EXIT_FAILURE);
      }
		ninode=verifExistence(tmp);
	}
    int etat=1;//sortie standard
    if(INODE[ninode].etat<0)//fichier non ouvert
		etat=myopen(ninode);
	
	if(etat==-1)//erreur lors de l ouverture
	{
		printf("il y a eu une erreur lors de l'ouverture du fichier\n");
		exit(EXIT_FAILURE);
	}
    myecho(etat, tab);
    return 0;
}


void myecho(int etat, char *chaine)
{
        mywrite(etat,chaine,sizeof(chaine));
        myclose(etat);
        return ;
}
