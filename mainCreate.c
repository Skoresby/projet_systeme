#include <stdlib.h>
#include <stdio.h>
#include "mycreate.h"
#include "vg.h"
#include "liste_chainee.h"
extern Inode *INODE;
extern VE VAR_E;

int main(int argc,char *argv[])
{
	int a =mycreate(argv[1],(mode_t)(argv[2][0]));
	return a;
}
