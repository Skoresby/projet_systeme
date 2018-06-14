#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variable_environnement.h"
#include "inode.h"

VE VAR_E;

 int verifType (char *objet, _Bool sudo) { //écriture de bool différente en fonction des versions
	 char *nom, *chemin;
	 int ninode = -1;//si aucune modif alors n'existe pas
	 int count = 0, rep = -1, type;
	 int *corresp;
	 
	 corresp = (int *)malloc(VE.nbInode*(sizeof (int )));
	 
	 (nom, chemin) = path(objet);
	 //(nom2, chemin2) = path(argv[2]);
	 
	 if(( sudo == 1) && (chemin == ""))
	 {
		 chemin = VE.mypath;
	 }
	 
	 if(nom == "")
	 {
		 type = 1; //repertoire
	 }
	 else if
	 {
		 for(i=0;i<VE.nbInode;i++)
		 {
			 if(tabInode[i].nom == nom)//liste correspondances
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
			 if((tabInode[i].nom == nom)&&(tabInode.chemin == chemin))
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
