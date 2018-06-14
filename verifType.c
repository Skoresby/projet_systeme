#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variable_environnement.h"
#include "inode.h"
#include "path.h"

VE VAR_E;

 int verifType (char *objet, _Bool sudo) { //écriture de bool différente en fonction des versions
	 char *nom, *chemin;
	 Path recup;
	 int ninode = -1;//si aucune modif alors n'existe pas
	 int count = 0, rep = -1, type, i;
	 int *corresp;
	 
	 corresp = (int *)malloc(VE.nbInode*(sizeof (int )));
	 
	 recup = path(objet);
	 //(nom2, chemin2) = path(argv[2]);
	 
	 if(( sudo == 1) && (recup.chemin == NULL))
	 {
		 recup.chemin=(char*)malloc(strlen(VAR_E.mypath)*sizeof(char));
		 recup.chemin = VAR_E.mypath;
	 }
	 
	 if(recup.nom ==NULL)
	 {
		 type = 1; //repertoire
	 }
	 else if(recup.chemin==NULL)//on n a pas modifié cette valeur, qui est toujours nulle
	 {
		 for(i=0;i<VAR_E.nbInode;i++)
		 {
			 if(tabInode[i].nom == recup.nom)//liste correspondances
			 {
				 corresp[count]=i; //ninodes correspondantes
				 printf("%d %s\n",count, tabInode[i].chemin);
				 count ++;
			 }
		 }
		 if(count == 1)//une seule correspondance
		 {
			 ninode = corresp[0];
		 }
		 else //plusieurs correspondances -> demande choix utilisateur
		 {
			 do{
				 printf("Entrez le n° correspondant au chemin voulu\n");
				 scanf("%d", rep);
				 if((0 < rep ) && (rep < count))
				 {
					ninode = corresp[rep];
				 }
				 else
					printf("Réponse saisie incorrecte\n");
				}while((0 > rep ) || (rep > count));
		 }
	 }
	 else
	 {
		 for(i=0;i<VE.nbInode;i++)
		 {
			 if((tabInode[i].nom == recup.nom)&&(tabInode.chemin == recup.chemin))
			 {
				 ninode = i;
				 break;
			 }
		 }
	 }
	 if(ninode == -1)
	 {
		 printf("N'existe pas\n");
		 type = -1;
	 }
		
	 else
		type = tabInode[ninode].type;
		
	return type;
}
