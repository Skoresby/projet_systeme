#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variable_environnement.h"

//#define PATH "/variable/d/environnement/"

typedef struct 
{
	char *chemin;
	char *nom;
}Path;

extern VE ve;

Path path(char* arg, int provenance);
Path separer(char* arg);


Path path(char* arg, int provenance)//si provenance=0, on ne met rien dans chemin si le chemin n'est pas absolu, sinon si vient de cd, on le met meme si ne commence ni par . ni par /sinon (-1) on met le chemin courant 
{
	Path retour, tmp;
	
	char * ptArg=arg;//le pointeur va se deplacer dans arg
	char * doublePath=ve.mypath;
	if(arg[0]=='/')//donc on a directement le chemin absolu
	{
		tmp=separer(arg);
		if(arg[strlen(arg)-1]=='/')//finit par un '/', donc c est un repertoire
		{
			retour.chemin=(char*)malloc((strlen(tmp.nom)+strlen(tmp.chemin))*sizeof(char));
			strcpy(retour.chemin, tmp.chemin);
			strcat(retour.chemin, tmp.nom);
			retour.nom=NULL;
		}
		else
		{
			retour=separer(arg);
		}
		
	}
	else if(arg[0]=='.')//donc on a le chemin absolu en regardant via le chemin courant
	{
		int temD=0, i;//temS=0, 
		char* chaine;
		while((ptArg[0]=='.')&&(ptArg[1]=='/'))//enchainement de "./"
		{
			ptArg=strcpy(ptArg, ptArg+2);//on enleve le ./
		}
		
		
		while((ptArg[temD*3]=='.')&&(ptArg[temD*3+1]=='.')&&(ptArg[temD*3+2]=='/'))//enchainement de ../	
			temD++;
		
		for(i=0; i<temD; i++)
		{
			ptArg=strcpy(ptArg, ptArg+3);//on enleve un "../"
			
			tmp=separer(doublePath);
			memset(doublePath, 0, strlen(doublePath));
			strcpy(doublePath, tmp.chemin);
		}

		chaine=(char*)malloc((strlen(ptArg)+strlen(doublePath))*sizeof(char));
		strcpy(chaine, doublePath);
		strcat(chaine, ptArg);
		printf("93 : chaine obtenue : %s\n", chaine);
		tmp=separer(chaine);//la separation reelle
		printf("95 donc nous avons donc dit nom=%s, chemin=%s\n", tmp.nom, tmp.chemin);
		if(arg[strlen(arg)-1]=='/')//finit par un '/', donc c est un repertoire
		{
			retour.chemin=(char*)malloc(strlen(chaine)*sizeof(char));
			strcpy(retour.chemin, chaine);
			retour.nom=NULL;
		}
		else
			retour=tmp;
		
	}
	else//on commence sans chemin relatif, ce qui n est possible que si provenance vaut 2(vient de cd)
	{
		if(provenance==2)
		{
			retour=separer(arg);
		}
		else if(provenance==0)
		{
			tmp=separer(arg);
			retour.nom=(char*)malloc(strlen(tmp.nom)*sizeof(char));
			strcpy(retour.nom, tmp.nom);
			retour.chemin=NULL;
		}
		else
		{
			printf("erreur : il faut donner le chemin absolu ou relatif\n");
		}
	}
	
	return retour;
}


Path separer(char* arg)
{
	Path tmp;
	int countMotActuel=0, i;
	char chemin[200]="", nom[200]="", motActuel[200]="", motPrecedent[200]="";

	for(i=0; i<strlen(arg); i++)//on verifie caractere par caractere si on a un nouveau mot ou non
	{
		if(arg[i]!='/')//n'est pas un '/', donc on est encore au milieu du "mot"
		{
			motActuel[countMotActuel]=arg[i];
			countMotActuel++;
		}
		else if((i<strlen(arg)-1))//si ca finit par un /, faut pas etre gene
		{
			strcat(chemin, motPrecedent);//on remonte la chaine des mots enregistrés
			memset (motPrecedent, 0, sizeof (motPrecedent));
			strcat(motPrecedent, motActuel);
			strcat (motPrecedent, "/");
			countMotActuel=0;
			memset (motActuel, 0, sizeof (motActuel));
		}
		else if(provenance==3)//si chemin null, on renvoie le chemin courant
		{
			tmp=separer(arg);
		retour.nom=(char*)malloc(strlen(tmp.nom)*sizeof(char));
		strcpy(retour.nom, tmp.nom);

		retour.chemin=(char*)malloc((strlen(VAR_E.mypath)+strlen(tmp.chemin))*sizeof(char));
		strcpy(retour.chemin, VAR_E.mypath);
		strcat(retour.chemin, tmp.chemin);
		printf("ch=%s, n=%s\n", retour.chemin, retour.nom);
		}
	}
	
	
	strcat(chemin, motPrecedent);
	strcat(nom, motActuel);
	tmp.chemin=(char*)malloc(strlen(chemin)*sizeof(char));
	strcpy(tmp.chemin, chemin);
	
	tmp.nom=(char*)malloc(strlen(nom)*sizeof(char));
	strcpy(tmp.nom, nom);
	return tmp;
	
}
	
	




