#ifndef MYWRITE_H
#define MYWRITE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void mywrite(int ninode,char buf[], int nombre);

#endif
