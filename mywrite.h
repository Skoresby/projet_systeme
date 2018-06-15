#ifndef MYWRITE_H
#define MYWRITE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "inode.h"
#include "vg.h"
# include "myopen.h"
# include "myclose.h"
#include "liste_chainee.h"
#include "variable_environnement.h"


void mywrite(int ninode,char buf[], int nombre);

#endif
