#include "myls.h"

void myls (char *argv[])
{
	int ninode = -1;
	int type = -1;
	Path pathLs;
	
	if(argv[1] != NULL)/*ls avec une option*/
	{
		if(argv[1][0] != '-') /*ls avec option*/
		{
			/*différentes options (même s'il n'y a actuellement que -l de diponible)*/
			switch (argv[1][1])
			{
				case l : /*ls -l*/
						printf("ls -l\n");
						if(argv[2] == NULL)/*ls -l seul*/
						{
							affiche_ls(argv[2],1);
						}
						else if(argv[2][0] != '-') /*ls avec plusieurs options*/
						{
							printf("option non gérée\n");
						}
						else /*ls -l sur un repertoire precis*/
						{
							pathLs = path(argv[2], 1);
							ninode = verifExistence(pathLs);
							type = verifType(argv[1],0);
							if((ninode == -1) || (type != 1))
							{
								printf("aucun répertoire de ce nom\n");
							}
							else /*est un répertoire et existe*/
							{
								affiche_ls(argv[2],0);
							}
						}
						break;
				default
					printf("option non gérée\n");
					break;
			}
		}
		else /*ls sur un nom de répertoire*/
		{
			/*vérification exitence répertoire*/
			pathLs = path(argv[1], 1);
			ninode = verifExistence(pathLs);
			type = verifType(argv[1],0);
			if((ninode == -1) || (type != 1))
			{
				printf("aucun répertoire de ce nom\n");
			}
			else /*est un répertoire et existe*/
			{
				affiche_ls(argv[1],0);
			}
		}
	}
	else /*ls simple*/
	{
		affiche_ls(VE.mypath,0);
	}	
}

void affiche_ls(char *repertoire, bool option)
{
	char buffer[100] = "";
	char contenu[30] = "";
	int ninode, i, j = 0;
	pathLs = path(repertoire, 1);
	ninode = verifExistence(pathLs);
	
	myread(ninode,buffer,INODE[ninode].taille);
	for(i=0;i<100;i++)
	{
		if(buffer[i] != ' ');
		{
			contenu[j] = buffer[i];
		}
		else
		{
			if(option == 1)
			{
				printf("%s %s\n", INODE[ninode].permissions , contenu);
			}
			else
			{
				printf("%s\n", contenu);
			}
			contenu[30] = "";/*reinitialise contenu*/
			j = 0;
		}
	}
}

