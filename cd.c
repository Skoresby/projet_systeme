#include "cd.h"
#include "liste_chainee.h"
extern VE VAR_E;

void cd (char *chemin)
{
	char *cheminFinal;
	char *cheminInt;
	Path path;
	printf("lenght %d \n", strlen(chemin));
	if((chemin[0] == '.') && (chemin[1] == '.') && strlen(chemin))/*pour "cd .."*/
	{
		cheminFinal=(char*)malloc((strlen(VAR_E.mypath)-1)*sizeof(char));
		cheminInt=(char*)malloc((strlen(VAR_E.mypath)-1)*sizeof(char));
		memcpy ( cheminInt, VAR_E.mypath, strlen(VAR_E.mypath)-1);/*suppression du "/" en fin du chemin actuel*/
		path = separer(cheminInt);/*aller au repertoire precedent*/
		cheminFinal = path.chemin;
	}
	else if (chemin[0] == '/') /*chemin est un chemin absolu*/
	{
		/*modifier inode.path direct*/
		cheminFinal=(char*)malloc((strlen(chemin)*sizeof(char));
		cheminFinal = chemin;
	}
	else /*chemin est un chemin relatif par rapport aà inode.path*/
	{
		/*concatener inode.path et chemin*/
		cheminFinal=(char*)malloc((strlen(VAR_E.mypath)+strlen(chemin))*sizeof(char));
		strcpy(cheminFinal, VAR_E.mypath);
		strcat(cheminFinal, chemin);
	}
	/*vérification de l'existance*/
	memcpy ( cheminInt, cheminFinal, strlen(cheminFinal)-1);
	path = separer(cheminInt);
	if(verifExistence(path) != -1)
	{
		VAR_E.mypath = cheminFinal;
	}
	else
		printf("le chemin n'existe pas\n");
}

