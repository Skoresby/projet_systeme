#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "inode.h"
#include "path.h"
#include "liste_chainee.h"
#include "variable_environnement.h"
#include "vg.h"
#include "ln.h"
#include "verifExistence.h"
#include "verifType.h"
#include "mycreate.h"


extern Inode* INODE;
extern char** tabBlocs;
extern L_Bloc * listeBloc;
extern L_Bloc * listeInode;

void mylink(Path nom1 ,Path nom2)
{
   
    char * var = (char*)malloc((strlen(nom2.chemin)+strlen(nom2.nom))*sizeof(char));
    strcpy(var,nom2.chemin);
    strcat(var,nom2.nom);
    int etat_fichier2 = 0;
    etat_fichier2 = mycreate(var,6);
    if(etat_fichier2>2)
    {

         INODE[verifExistence(nom2)].lbloc = INODE[verifExistence(nom1)].lbloc;
         INODE[verifExistence(nom1)].numinode_liens =(int*)realloc(INODE[verifExistence(nom1)].numinode_liens,1*sizeof(int));
         INODE[verifExistence(nom1)].numinode_liens[ INODE[verifExistence(nom1)].nb_lien]=verifExistence(nom2);
         INODE[verifExistence(nom1)].nb_lien++;

         if(INODE[verifExistence(nom1)].nb_lien>1)
         {
             int i=0;
             for(i=0;i<INODE[verifExistence(nom1)].nb_lien-1;i++)
             {

                INODE[INODE[verifExistence(nom1)].numinode_liens[i]].nb_lien = INODE[verifExistence(nom1)].nb_lien;
                INODE[INODE[verifExistence(nom1)].numinode_liens[i]].numinode_liens = (int*)realloc(INODE[INODE[verifExistence(nom1)].numinode_liens[i]].numinode_liens,1 * sizeof(int));
                INODE[INODE[verifExistence(nom1)].numinode_liens[i]].numinode_liens[ INODE[INODE[verifExistence(nom1)].numinode_liens[i]].nb_lien]=verifExistence(nom2);
             }
         }
    }
    else
    {
        printf(" Erreur lors de la création du lien !");
    }

}
