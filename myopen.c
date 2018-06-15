#include "myopen.h"
#include "variable_environnement.h"
#include "inode.h"
#include "vg.h"

int myopen(int indice)
{
	char dpath[100]="";
	char nom[100]="";
	strcat(nom,INODE[indice].nom_fichier);
//	printf("%s \n",nom);
	strcat(dpath,INODE[indice].chemin_absolu);
//	printf("%s \n",dpath);
	strcat(dpath,nom);
//	printf("%s \n",dpath);
	int retour = open(dpath,O_RDWR|O_CREAT|O_APPEND );
	INODE[indice].etat = retour;
	return retour; // renvoie  -1 si il ne trouve pas le fichier, sinon renvoie la valeur correspondant au descripteur de fichier
}



int main (int argc, char **argv)
{

	int a = myopen(argv[1]);  
	printf("nouvel etat : %d \n",a);
	return a;
}
