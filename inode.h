#ifndef INODE_H
#define INODE_H

typedef struct 
{
 int permissions;
 char *chemin_absolu;
 char *nom_fichier;
 char *d_last_mod;
 int version;
 L_Bloc * lbloc;
 int taille;
 char *n_pro;
 int etat;
 int nb_lien;
 int *numinode_liens;
 int type;
}Inode;

#endif

