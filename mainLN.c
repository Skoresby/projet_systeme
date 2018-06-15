#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variable_environnement.h"
#include "inode.h"
#include "ln.h"

extern VE VAR_E;
extern Inode* INODE;

int main(int argc, char* argv [])
{
	ln(argv);
	return 0;
}
