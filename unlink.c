#include "path.h"
#include "variable_environnement.h"
#include "inode.h"
#include "liste_chainee.h"

extern Inode* INODE;
extern char** tabBlocs;
extern L_Bloc * listeBloc;
extern L_Bloc * listeInode;

void unlink(char *nom)
{
	
	Path monPath;
	monPath=path(nom, 1);/*1 pour obliger a avoir un chemin relatif ou absolu*/
	/*printf("on recherche : nom=%s, chemin=%s\n", monPath.nom, monPath.chemin);*/
	int ninode=verifExistence(monPath);
	if(INODE[ninode].type=='r')/*repertoire*/
	{
		printf("impossible de supprimer un répertoire avec cette commande\n");
		exit(EXIT_FAILURE);
	}
	if(ninode==-1)
	{
		printf("fichier introuvable\n");
		exit(EXIT_FAILURE);
	}
	
	if(INODE[ninode].nb_lien>1)/*il y a d autres fichiers pointant vers les blocs de données*/
	{
		int i, j, ninodeAutreLien, tem, nbreLiens=INODE[ninode].nb_lien;
		for(i=0; i<nbreLiens-1; i++)
		{
			tem=0;
			ninodeAutreLien=INODE[ninode].numinode_liens[i];
			/*on regarde a quelle place dans le tableaux des ninodes pointant sur le meme fichier le ninode qu on veut supp est.*/
			while((tem<nbreLiens-1)&&(INODE[ninodeAutreLien].numinode_liens[tem]!=ninode))
				tem++;
				
			/*on echange cette case avec la derniere (pas besoin de remettre la valeur, elle va etre supprimee de toute facon*/
			/*printf("supp de %d dans %d\n", Inode[ninodeAutreLien].numinode_liens[tem], ninodeAutreLien);*/
			INODE[ninodeAutreLien].numinode_liens[tem]=INODE[ninodeAutreLien].numinode_liens[nbreLiens-1];
			int *tmp=(int*)malloc((nbreLiens-1)*sizeof(int));
			for(j=0; j<nbreLiens-1; j++)
				tmp[j]=INODE[ninodeAutreLien].numinode_liens[j];
			memset(INODE[ninodeAutreLien].numinode_liens, 0, INODE[ninodeAutreLien].nb_lien);
			INODE[ninodeAutreLien].numinode_liens=(int*)malloc((nbreLiens-1)*sizeof(int));
			for(j=0; j<nbreLiens-1; j++)
				INODE[ninodeAutreLien].numinode_liens[j]=tmp[j];
			INODE[ninodeAutreLien].nb_lien--;
		}
		
	}
	else/*donc il faut supp l inode et les blocs*/
	{
		int numBlocs[15], i;/*on a dit que chaque fichier avait au plus 15 blocs de données*/
		/*supp des blocs*/
		recup_list_bloc(INODE[ninode].bloc, numBlocs);
		for(i=0; i<15; i++)
		{
			if(numBlocs[i]==-1)
				break;
			memset(tabBlocs[numBlocs[i]], 0, strlen(tabBlocs[numBlocs[i]]));
			if(listeBloc==NULL)
				listeBloc=initBloc(numBlocs[i]);
			else
				insertbloc(listeBloc, numBlocs[i]);
		}
	}
	
	/*reinitialisation de l i-node (dans tous les cas)*/
	INODE[ninode].permissions=0;
	memset(INODE[ninode].chemin_absolu, 0, strlen(INODE[ninode].chemin_absolu));
	memset(INODE[ninode].nom_fichier, 0, strlen(INODE[ninode].nom_fichier));
	memset(INODE[ninode].d_last_mod, 0, strlen(INODE[ninode].d_last_mod));
	INODE[ninode].version=0;
	INODE[ninode].type=-1;
	INODE[ninode].bloc=NULL;
	INODE[ninode].taille=0;
	memset(INODE[ninode].n_pro, 0, strlen(INODE[ninode].n_pro));
	INODE[ninode].etat=-1;
	INODE[ninode].nb_lien=0;
	INODE[ninode].numinode_liens=NULL;
	
	/*printf("inode %d supp\n", ninode);*/
	
	/*placement de l'i-node dans la liste chainée des ninodes non utilisés*/
	if(listeInode==NULL)
		listeInode=initBloc(ninode);
	else
		insertbloc(listeInode,ninode);
}
