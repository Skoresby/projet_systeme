#include <stdlib.h>
#include <stdio.h>
#include "variable_environnement.h"
#include "inode.h"
#include "mkdir.h"
#include "vg.h"
#include "mycreate.h"
#include "liste_chainee.h"

extern Inode* INODE;
extern VE VAR_E;

int mkdir(char *argv[])
{
	
	int i = mycreate(argv[1],2);
	
	return i;

}
