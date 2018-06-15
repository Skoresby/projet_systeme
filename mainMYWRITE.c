#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "inode.h"
#include "vg.h"
# include myopen.h"
# include myclose.h"
#include "liste_chainee.h"
#include "variable_environnement.h"


extern Inode* INODE;
extern char** tabBlocs;
extern L_Bloc * listeBloc;
extern L_Bloc * listeInode;


int main(int argc, char* argv [])
{
	mywrite(ninode,buf,nombre);
	return 0;
}
