#include  "liste_chainee.h"
//#include <stdio.h>
#include <stdlib.h>
//#include <string.h>


L_Bloc *initBloc(int x)
{
    L_Bloc *lbloc =(L_Bloc*) malloc(sizeof(L_Bloc));
    Bloc *bloc = (Bloc*) malloc(sizeof(Bloc));

    if (lbloc == NULL || bloc == NULL)
    {
        exit(EXIT_FAILURE);
    }
    bloc->indice = x;
    bloc->suivant = NULL;
    lbloc->premier = bloc;
    return lbloc;
}

void aff_list_lbloc(L_Bloc *lbloc )
{
    if (lbloc == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Bloc *courant = lbloc->premier;
    while (courant!= NULL)
    {
        printf("%d -> ", courant->indice);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

void recup_list_bloc(L_Bloc* lbloc, int recup[15])
{
	/*int recup[15];*/
	printf("lc 38\n");
	int i=0, j;
	if (lbloc == NULL)
    {
		printf("liste vide, on sort\n");
        exit(EXIT_FAILURE);
    }
    Bloc *courant = lbloc->premier;
    while (courant!= NULL)
    {
		recup[i]=courant->indice;
		i++;
        courant = courant->suivant;
    }
    for(j=i; j<15; j++)
		recup[j]=-1;
		
	printf("lc 54\n");
	/*return recup;*/
}

void insertbloc(L_Bloc * lbloc,int x)
{

  Bloc * last_point = NULL;
  Bloc *bloc = (Bloc*)malloc(sizeof(Bloc));
    if (lbloc == NULL || bloc == NULL)
  {
        exit(EXIT_FAILURE);
  }
  bloc->indice = x;
  last_point = lbloc->premier;
  while(last_point!= NULL)
  {
        if(last_point->suivant == NULL)
        {
            break;
        }
        last_point = last_point->suivant;
  }
  bloc->suivant = NULL;
  last_point->suivant = bloc;
}



