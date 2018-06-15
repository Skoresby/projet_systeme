
#include "bash.h"
#include "variable_environnement.h"

Inode *tabInode;
int nbInode;
VE VAR_E;

int main(int argc,char *argv[])
{
	if(argc <3)
	{
		printf("nombre de parametre insuffisant \n");
		exit(EXIT_FAILURE);
	}
	  //path(argv[1],1);
	//echo(argc,argv);
	nbInode=0;
    
   
	int v;
	v=atoi(argv[2]);
	mode_t mode;
	printf("%d \n",v);
	strcat(VAR_E.mypath,"/bonjour/ca/va/kyndra/");
	int mode_N=100*v;//quite le type mode et afficher les droits d'acces normaux
	mode=0100*v;//ne jamais retirer le 0 devant 
	time_t t =time(NULL);
	char *tt=ctime(&t);
	
	if(nbInode==0)//tableau vide
    {
		//Inode tabInode;
		mycreate(argv[1],mode);
		tabInode=(Inode*)malloc(sizeof(Inode));
		nbInode+=1;
		memcpy(tabInode[0].nom_fichier,argv[1],strlen(argv[1])+1);
		tabInode[0].permissions=mode_N;
		tabInode[0].etat=-1;
		
		memcpy(tabInode[0].d_last_mod,tt,strlen(tt)+1);
		tabInode[0].type='f';
		tabInode[0].taille=1;
		char propr[]="isty";
		memcpy(tabInode[0].n_pro,propr,strlen(propr)+1);
		tabInode[0].nb_lien=1;
//		nbInode++;
	}
	else
     {
		 mycreate(argv[1],mode);
		nbInode+=1;
		Inode* tmp=(Inode*)malloc(nbInode*sizeof(Inode));
		int i;
		for(i=0;i<nbInode-1;i++)
		{
			
			tmp[i]=tabInode[i];
		}
		tabInode=NULL;
		tabInode=(Inode*)malloc(nbInode*sizeof(Inode));
		for(i=0;i<nbInode;i++)
		{
			
			tabInode[i]=tmp[i];
		}
		tmp=NULL;
		memcpy(tabInode[nbInode-1].nom_fichier,argv[1],strlen(argv[1])+1);
		tabInode[nbInode-1].permissions=mode_N;
		tabInode[nbInode-1].etat=-1;
		time_t t =time(NULL);
		char *tt=ctime(&t);
		memcpy(tabInode[nbInode-1].d_last_mod,tt,strlen(tt)+1);
		tabInode[nbInode-1].type='f';
		tabInode[nbInode-1].taille=1;
		char propr[]="isty";
		memcpy(tabInode[nbInode-1].n_pro,propr,strlen(propr)+1);
		tabInode[nbInode-1].nb_lien=1;
	//	nbInode++;
}
	printf("la nom du fichier créer est %s \n",tabInode[0].nom_fichier);
	printf("les permissions du fichier créer sont  %d \n",tabInode[0].permissions);
	printf("l'etat du fichier créer est  %d \n",tabInode[0].etat);
	printf(" la date  de la derniere modifiacation est %s \n",tt);
	printf(" le type: %c  \n",tabInode[0].type);
	printf("taille du fichier: %d  \n",tabInode[0].taille);
	printf("nom du propietaire: %s  \n",tabInode[0].n_pro);
	printf("nbre de liens: %d  \n",tabInode[0].nb_lien);
    printf("le valeur de Inode est %d  \n",nbInode);
	return 0;
}
