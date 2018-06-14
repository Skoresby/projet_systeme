#include "structInode.h"
#include <stdbool.h>
#include <string.h>

extern Inode *tabInode;
extern int nbreInode;

int verifExistence(Path chemin)
{
	int i;
	int ninode=-1;//retourne -1 si n existe pas, ninode sinon
	for(i=0; i<nbreInode; i++)
	{
		//printf("t[i].nom=%s, c.nom=%s\nt[i]chem=%s, c.chem=%s\n", tabInode[i].nom_fichier, chemin.nom, tabInode[i].chemin_absolu, chemin.chemin);
		if((strcmp(tabInode[i].nom_fichier, chemin.nom)==0)&&(strcmp(tabInode[i].chemin_absolu, chemin.chemin)==0))
		{
			ninode=i;
			break;
		}
	}
	return ninode;
	
}
