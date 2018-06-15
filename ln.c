#include "ln.h"
#include <string.h>
#include <stdbool.h>
#include "path.h"
#include "liste_chainee.h"
#include "variable_environnement.h"
#include "verifExistence.h"
#include "verifType.h"
#include "vg.h"

extern VE VAR_E;

void ln(char * argv[])
{
	Path arg1, arg2;
	arg1=path(argv[1], 0);/*0 pour demander le chemin si celui ci n est pas rempli*/
	arg2=path(argv[2], 1);
	if(arg2.chemin==NULL)/*si le deuxieme argument n a pas de chemin, on le place dans le repertoire courant*/
	{
		arg2.chemin=(char*)malloc(strlen(VAR_E.mypath)*sizeof(char));
		strcpy(arg2.chemin, VAR_E.mypath);
	}
	
	int ninode2; 
	ninode2=verifExistence(arg2);
	
	if(ninode2!=-1)/* l existance de arg1 est verifiee avec verifType!*/
	{
		printf("probleme rencontre : le deuxieme argument existe\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int type;
		char* tmp=(char*)malloc((strlen(arg1.nom)+strlen(arg1.chemin))*sizeof(char));
		strcat(tmp, arg1.chemin);
		strcat(tmp, arg1.nom);
		type=verifType(tmp, 0);
		if(type==2)//si c est un lien
		{
			printf("on ne fait pas de lien symbolique, que des liens physiques. veuillez ne pas pointer sur un lien.\n");
			exit(EXIT_FAILURE);
		}
		link(arg1, arg2);
		
	}
}

