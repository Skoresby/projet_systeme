#ifndef MYREAD_H
#define MYREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "inode.h"
#include "vg.h"
#include "myopen.h"
#include "myclose.h"

void myread(int ninode, char buf[] ,int nombre);

#endif
