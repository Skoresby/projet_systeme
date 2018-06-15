#include <stdbool.h>
#include <string.h>
#include "inode.h"
#include "path.h"
#include "liste_chainee.h"
#include "variable_environnement.h"
#include "vg.h"


extern Inode* INODE;
extern VE VAR_E;

int verifExistence(Path cheminTest)
{
	int i, count=0, rep;
	int *correspondance=(int*)malloc(VAR_E.nbNinode*sizeof(int));
	int ninode=-1;/*retourne -1 si n existe pas, ninode sinon*/
	for(i=0; i<VAR_E.nbNinode; i++)
	{
		/*if(strlen(chemin.chemin)!=0)//chemin non vide*/
		if(cheminTest.chemin!=NULL)
		{
			/*printf("tb.n=%s, c.n=%s, tb.c=%s, c.c=%s\n", INODE[i].nom_fichier, chemin.nom, INODE[i].chemin_absolu,  chemin.chemin);*/
			if((strcmp(INODE[i].nom_fichier, cheminTest.nom)==0)&&(strcmp(INODE[i].chemin_absolu, cheminTest.chemin)==0))
			{
				ninode=i;
				break;
			}
		}
		else
		{
			if(strcmp(INODE[i].nom_fichier, cheminTest.nom)==0)
			{
				printf("correspondance numéro %d : chemin=%s\n", count, INODE[i].chemin_absolu);
				correspondance[count]=i;
				count++;
			}
		}
	}
	
	if(cheminTest.chemin==NULL)/*chemin vide, on demande de choisir*/
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
