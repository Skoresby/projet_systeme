#ifndef LISTE_CHAINEE_H
#define LISTE_CHAINEE_H

/*define verifType 0*/

typedef struct t_Bloc 
{
    int indice;
    struct t_Bloc *suivant;
}Bloc;

typedef struct L_Bloc L_Bloc;
struct L_Bloc
{
   Bloc *premier;
};

L_Bloc *initBloc(int valeur);
void aff_list_lbloc(L_Bloc *lbloc );
void insertbloc(L_Bloc * lbloc,int x);
void recup_list_bloc(L_Bloc* lbloc, int recup[15]);



#endif
