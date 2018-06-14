#include "structInode.h"
#include "variable_environnement.h"
#include <stdbool.h>
#include <string.h>

extern Inode *tabInode;
extern VE ve;
//extern int nbreInode;

int verifExistence(Path chemin)
{
	int i, count=0, rep;
	int *correspondance=(int*)malloc(ve.nbNinode*sizeof(int));
	int ninode=-1;//retourne -1 si n existe pas, ninode sinon
	for(i=0; i<ve.nbNinode; i++)
	{
		//if(strlen(chemin.chemin)!=0)//chemin non vide
		if(chemin.chemin!=NULL)
		{
			//printf("tb.n=%s, c.n=%s, tb.c=%s, c.c=%s\n", tabInode[i].nom_fichier, chemin.nom, tabInode[i].chemin_absolu,  chemin.chemin);
			if((strcmp(tabInode[i].nom_fichier, chemin.nom)==0)&&(strcmp(tabInode[i].chemin_absolu, chemin.chemin)==0))
			{
				ninode=i;
				break;
			}
		}
		else
		{
			if(strcmp(tabInode[i].nom_fichier, chemin.nom)==0)
			{
				printf("correspondance numéro %d : chemin=%s\n", count, tabInode[i].chemin_absolu);
				correspondance[count]=i;
				count++;
			}
		}
	}
	
	if(chemin.chemin==NULL)//chemin vide, on demande de choisir
	{
		do
		{
			printf("quel numéro choisir?\n");
			scanf(" %d",&rep);
		}while ((rep<0)&&(rep>count));
		ninode=correspondance[rep];
	}
	
	return ninode;
	
}
