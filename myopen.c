#include "myopen.h"
#include "variable_environnement.h"
#include "inode.h"
#include "vg.h"
#include "liste_chainee.h"
int myopen(int indice)
{
	char dpath[100]="";
	char nom[100]="";
	strcat(nom,INODE[indice].nom_fichier);
	strcat(dpath,INODE[indice].chemin_absolu);
	strcat(dpath,nom);
	int retour = open(dpath,O_RDWR|O_CREAT|O_APPEND );
	INODE[indice].etat = retour;
	return retour; // renvoie  -1 si il ne trouve pas le fichier, sinon renvoie la valeur correspondant au descripteur de fichier
}
