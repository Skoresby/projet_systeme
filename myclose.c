#include "myclose.h"
#include "inode.h"

int myclose(int etat)
{
	int i,retour=-1;
	for (i=0;i<VE.nbNinode;i++) //taille du tableau d'inode, a remplacer par la const globale représentant la taille du tableau d'inode
	{
		if (INODE[i].etat == etat) // on cherche dans le tableau d'inode l'inode qui a le meme etat que celui en argument (on verifie l'existence du fichier donc)
		{
        		retour = close(etat);
			tabInode[i].etat = retour-1;
		}
	}
	return retour -1;
}
int main (int argc, char **argv)
{

	int a = myclose(argv[1]);  
	printf("nouvel etat : %d \n",a);
	return a;
}
