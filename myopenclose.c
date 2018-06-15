#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
typedef struct Inode Inode;
struct Inode

{
 char permissions[10];
 char chemin_absolu[100];
 char nom_fichier[30];
 char d_last_mod[10];
 int version;
 char type;
 int mode;
 int bloc;
 int taille;
 char n_pro[30];
 int etat;
 int nb_lien;
 char n_gr[30];
 int *numinode_liens;
};

//#ifdef TAB
//#define TAB
Inode tabInode[3] ={{"-rwx_wxrwx","/home/daniel/","test.txt","2017-08-12",1,'f',2,3,4757,"HUGO",-1,2,"ETU",NULL},{"drwx_wxr_x","/","teest.txt","2015-02-02",1,'d',1,3,8572,"BART",-1,1,"ETU",NULL}};
//#endif
int myopen(int indice)
{
	char dpath[100]="";
	char nom[100]="";
	strcat(nom,tabInode[indice].nom_fichier);
	printf("%s \n",nom);
	strcat(dpath,tabInode[indice].chemin_absolu);
	printf("%s \n",dpath);
	strcat(dpath,nom);
	printf("%s \n",dpath);
	int retour = open(dpath,O_RDWR );
	tabInode[indice].etat = retour;
	return retour; // renvoie  -1 si il ne trouve pas le fichier, sinon renvoie la valeur correspondant au descripteur de fichier
	/*for (i=0;i<3;i++)
	{
	FILE *fp;
	verif =strcmp(tabnode[i].nom_fichier,nom);
	printf(" %d \n",verif);
	printf(" %s %s \n",tabnode[i].nom_fichier, nom);
	if ( verif  == 0)
	{
			found++;
			printf("%s\n",tabnode[i].chemin_absolu);
			strcpy(paths[p],tabnode[i].chemin_absolu);
			p++; 
	}
	}
	if (found == 0)
	{
		printf("fichier non trouvé dans le tableau d'inode \n");
		//mycreate
	}
	else
	{
		printf("fichier trouvé dans inode, présentation du ou des path(s) \n");
		for (i = 0; i<p;i++)
		{
			printf("[%d] %s \n",i+1,paths[i]);
		}
	        if (found > 1)
                {
                	printf(" Choisissez le chemin que vous voulez prendre en indiquant le numéro dans [] \n");
                        scanf("%d",&input);
                        printf("%d \n",input);
			if ((input > 0) && (input <= found ))
			{
				printf("commande valide \n");
			}
			else
			{
				printf(" commande invalide, renvoie avec message d'erreur \n");
				return -10;
			}
                }
		else
		{
			dpaths = paths[0]
			strcat(nom,dpaths);
			printf(" %s ",dpaths);
		}

	}*/
}


int myclose(int etat)
{
	int i;
	for (i=0;i<2;i++) //taille du tableau d'inode, a remplacer par la const globale représentant la taille du tableau d'inode
	{
		if (tabInode[i].etat == etat) // on cherche dans le tableau d'inode l'inode qui a le meme etat que celui en argument (on verifie l'existence du fichier donc)
		{
        		int retour = close(etat);
			tabInode[i].etat = retour-1;
        		return retour-1; // renvoie -1 si il a correctement fermeé, sinon -2
		}
	}
	return -2;
}
int main (void)
{

	//Inode tabInode[3] ={{"-rwx_wxrwx","/home/daniel/","test.txt","2017-08-12",1,'f',2,3,4757,"HUGO",-1,2,"ETU",NULL},{"drwx_wxr_x","/","teest.txt","2015-02-02",1,'d',1,3,8572,"BART",-1,1,"ETU",NULL},{"-rwx_wxrwx","/file.txt","file.txt","2009-04-02",1,'f',2,3,4388,"Arry",-1,2,"ETU",NULL}};
	int a = myopen(0); // entre l'indice dans le tableau du fichier que tu veut ouvrir
	printf("%d \n",tabInode[0].etat); 
	printf("%d \n",a);
	a= myclose(a); // met en entrée le descripteur de fichier du tableau Inode
	printf("%d",a);
}
