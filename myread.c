#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "inode.h"
#include "vg.h"
#include "myopen.h"
#include "myclose.h"
#include "liste_chainee.h"

extern Inode* INODE;

void myread(int ninode, char buf[] ,int nombre)
{

  if(INODE[ninode].etat==-2)
  {
      printf(" Une erreur s'est produite au niveau du fichier! ");
  }
  else
        {
           printf("\n fichier ferme");
            int fd =0,i=0 ,lu=0; char * car = NULL;
            char *c =NULL;
            fd = myopen(ninode);
            printf("fd = %d \n",fd);
            if((fd != 0)&&(fd !=-1))
            {

                for(i=0;i<nombre;i++)
                {
                    lu = read(fd,c,sizeof(char));
                    //printf("%c ",c);
                    car = &buf[i];
                    *car = *c;
                }

                int ferme = myclose(INODE[ninode].etat);
                if (ferme==-2)
                {
                  printf("Impossible de fermer le fichier %s",INODE[ninode].nom_fichier);
                }
            }
            else
            {
                printf("\n Echec de l'ouverture du fichier %s.\n", INODE[ninode].nom_fichier);
            }
    }

}
