#include <stdlib.h>
#include <stdio.h>
#include "myclose.h"
#include "inode.h"
#include "variable_environnement.h"
#include "vg.h"

extern Inode* INODE;
extern VE VAR_E;

int myclose(int etat)
{
	int i,retour=-1;
	for (i=0;i<VAR_E.nbNinode;i++) //taille du tableau d'inode, a remplacer par la const globale représentant la taille du tableau d'inode
	{
		if (INODE[i].etat == etat) // on cherche dans le tableau d'inode l'inode qui a le meme etat que celui en argument (on verifie l'existence du fichier donc)
		{
        		retour = close(etat);
			INODE[i].etat = retour-1; // nous avons pensé comme amélioration à remplacer etat par -etat en cas d'échec de fermeture
			// du fichier, afin de retrouver ensuite le descripteur pour retenter un fermeture
		}
	}
	return retour-1;
}

