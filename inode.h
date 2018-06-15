#ifndef INODE_H
#define INODE_H

typedef struct 
{
 int permissions;
 char chemin_absolu[100];
 char nom_fichier[30];
 char d_last_mod[10];
 int version;
 char type;
 int mode;
 int bloc;
 int taille;
 char n_pro[30];
 int etat;
 int nb_lien;
 char n_gr[30];
 int *numinode_liens;
}Inode;

#endif

