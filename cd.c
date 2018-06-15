#include "cd.h"

void cd (char *chemin)
{
	char *cheminFinal;
	char *cheminInt;
	Path path;
	printf("lenght %d \n", strlen(chemin));
	if((chemin[0] == '.') && (chemin[1] == '.') && strlen(chemin))//pour "cd .."
	{
		cheminFinal=(char*)malloc((strlen(Inode.chemin_absolu)-1)*sizeof(char));
		cheminInt=(char*)malloc((strlen(Inode.chemin_absolu)-1)*sizeof(char));
		memcpy ( cheminInt, Inode.chemin_absolu, strlen(Inode.chemin_absolu)-1);//suppression du "/" en fin du chemin actuel
		path = separer(cheminInt);//aller au repertoire precedent
		cheminFinal = path.chemin;
	}
	else if (chemin[0] == '/') //chemin est un chemin absolu
	{
		//modifier inode.path direct
		cheminFinal=(char*)malloc((strlen(chemin)*sizeof(char));
		cheminFinal = chemin;
	}
	else //chemin est un chemin relatif par rapport aà inode.path
	{
		//concatener inode.path et chemin
		cheminFinal=(char*)malloc((strlen(Inode.chemin_absolu)+strlen(chemin))*sizeof(char));
		strcpy(cheminFinal, Inode.chemin_absolu);
		strcat(cheminFinal, chemin);
	}
	//vérification de l'existance
	if(verifExistence(cheminFinal) != -1)
	{
		Inode.chemin_absolu = cheminFinal;
	}
	else
		printf("le chemin n'existe pas\n");
}

