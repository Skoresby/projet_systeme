
#include "inode.h"
#include "vg.h"
# include "myopen.h"
# include "myclose.h"
#include "liste_chainee.h"
#include "variable_environnement.h"
#include "mywrite.h"

extern Inode* INODE;
extern char** tabBlocs;
extern L_Bloc * listeBloc;
extern L_Bloc * listeInode;

void mywrite(int ninode,char buf [], int nombre)
{

        if(INODE[ninode].etat==-2)
        {
            printf(" Une erreur s'est produite au niveau du fichier! ");
        }
        else
        {
            
            char buff[1000]="";int i=0;
            int sbuf=sizeof(buf),T_MAX=5120;// 5120 = 5*1024 5 blocs de 1024 octets au maximum pour chaque fichier
            int espace_restant=((int)sizeof(INODE[ninode].lbloc)*1024)-INODE[ninode].taille;
            for(i=0;i<nombre;i++)
            {
              buff[i]=buf[i];
            }
            if(sbuf<=espace_restant)
            {
                int fd =0;
                fd = myopen(ninode);
               // printf(" fd = %d  J'ecris car  sbuf<=espace_restant ",fd);
                if((fd != 0)&&(fd !=-1))
                 {
                    write(fd, buff, sizeof(buff));
           
                    INODE[ninode].version++;
                    INODE[ninode].taille = INODE[ninode].taille + sbuf;
                    if(INODE[ninode].nb_lien>0)
                    {
                          for(i=0;i<INODE[ninode].nb_lien;i++)
                          {
                            INODE[INODE[ninode].numinode_liens[i]].version++;
                          }
                    }
                    int ferme = myclose(INODE[ninode].etat);
                    if (ferme==-2)
                    {
                        printf("On a pas pu refermer le fichier %s",INODE[ninode].nom_fichier);             
                    }

                 }
                else
                {
                  printf("\n Echec de l'ouverture du fichier %s.\n", INODE[ninode].nom_fichier);
                }
            }
            else
            {
                if((sbuf-espace_restant)<(T_MAX-INODE[ninode].taille))
                {

                    printf(" Insertion d'un nouveau bloc \n");
                    insertbloc(INODE[ninode].lbloc,(ninode*5)+(INODE[ninode].version-1));
                    int fd =0;
                    fd = myopen(ninode);
                   // printf(" fd = %d  J'ecris car  sbuf<=espace_restant ",fd);
                    if((fd != 0)&&(fd !=-1))
                    {
                      write(fd, buff, sizeof(buff));
                      INODE[ninode].version++;
                      INODE[ninode].taille = INODE[ninode].taille + sbuf;
                      if(INODE[ninode].nb_lien>0)
                      {
                          for(i=0;i<INODE[ninode].nb_lien;i++)
                          {
                             INODE[INODE[ninode].numinode_liens[i]].version++;
                          }
                      }

                      int ferme = myclose(INODE[ninode].etat);
                      if (ferme==-2)
                      {
                        printf("On a pas pu refermer le fichier %s",INODE[ninode].nom_fichier);                    
                      }

                    }
                    else
                    {
                      printf("\n Echec de l'ouverture du fichier %s.\n", INODE[ninode].nom_fichier);
                    }
                }
                else if ((sbuf-espace_restant)==(T_MAX-INODE[ninode].taille))
                {

                    printf(" Insertion d'un nouveau bloc \n");
                    insertbloc(INODE[ninode].lbloc,(ninode*5)+(INODE[ninode].version-1));
                    int fd =0;
                    fd = myopen(ninode);
                    //printf(" fd = %d  J'ecris car  sbuf<=espace_restant ",fd);
                    if((fd != 0)&&(fd !=-1))
                    {
                      write(fd, buff, sizeof(buff));
                      
                      INODE[ninode].version++;
                      INODE[ninode].taille = INODE[ninode].taille + sbuf;
                      if(INODE[ninode].nb_lien>0)
                      {
                          for(i=0;i<INODE[ninode].nb_lien;i++)
                          {
                             INODE[INODE[ninode].numinode_liens[i]].version++;
                          }
                      }
                      printf(" Taille maximale atteinte après cet ajout , on ne pourra plus rien y écrire");
                      int ferme = myclose(INODE[ninode].etat);
                      if (ferme==-2)
                      {
                        printf("On a pas pu refermer le fichier %s !",INODE[ninode].nom_fichier);
                      }
                    }
                    else
                    {
                      printf("\n Echec de l'ouverture du fichier %s.\n", INODE[ninode].nom_fichier);
                      printf(" Taille maximale atteinte après cet ajout , on ne pourra plus rien y écrire");
                    }
                }
                else
                {
                    printf(" Taille des données excédant la capacité de stockage max pour ce fichier ! ");
                    
                }
            }
        }
}
