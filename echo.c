#include "bash.h"
#include "variable_environnement.h"

Inode *tabInode;
int nbInode;

int main(int argc,char *argv[])
{

   Inode tabInode[3];
        //char ntab[]="test.txt";
    memcpy(tabInode[0].nom_fichier,argv[1],strlen(argv[1])+1);
    //copie le nom du fichier pri en parametre dans tabInode[0]
    tabInode[0].permissions=700;
    char chemin[]="/UNIX/projet_unix/";
    memcpy(tabInode[0].chemin_absolu,chemin,strlen(chemin)+1);
    char date[]="2018-11-06";
    memcpy(tabInode[0].d_last_mod,date,strlen(date)+1);
    tabInode[0].version=1;
    tabInode[0].type='f';
    tabInode[0].bloc=2;
    tabInode[0].taille=12;
    char prop[]="kyndy";
    memcpy(tabInode[0].n_pro,prop,strlen(prop)+1);
    tabInode[0].etat=-1;
    tabInode[0].nb_lien=1;
        char tab[100]="";
    int i;
// on concaterne tout les arguments passé en paremetre à partir de
//argv[2]( pour ne par recuperer le non du fichier)
// et on stocque dans un tableau de chaine de caractere
        for(i=2;i<argc;i++)
        {
                strcat(tab , argv[i]);
                strcat(tab ," ");//espacer les mots de la chaine à redictionner dans
la //fichier

        }
        printf("%s \n",tab);
        //char *v[21];
        int k=0;
//on parcourt le tableau d'Inode pour rechercher le fichier passe
//en parametre
        for(k=0;k<3;k++)
        {
                if(argv[1]=tabInode[k].nom_fichier)
                {
                        printf("le fichier est bien dans la table des inods \n");
                     echo(argv[1],tab);
                 }
                 else
                 {
                         printf("le fichier est introuvable sur ce systeme \n");
                 exit(EXIT_FAILURE);
                 }
         }
        return 0;
}


void echo(char *fichier, char *chaine)
{
        int fd;

        //v[0]=argv[2];
        //v[1]=argv[3];
        //printf("le resulta est %s",strcat (v[1],v[0]));


        //redirection de la sortie vers le fichier passé en paramètre
        //dup2(fd ,1);
        //printf("%s \n",chaine);
        mywrite(0,chaine,sizeof(chaine));
        close(fd);
        return ;
}
