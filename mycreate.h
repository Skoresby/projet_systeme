#ifndef CREAT_H
#define CREAT_H

#include "verifExistence.h"
#include "inode.h"
#include "vg.h"
#include "mywrite.h"
#include "myopen.h"
#include "variable_environnement.h"
#include "myclose.h"
#include "liste_chainee.h"
#include "path.h"

int mycreate(char *fichier,int mode);

#endif