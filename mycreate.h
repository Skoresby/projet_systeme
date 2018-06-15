#ifndef CREAT_H
#define CREAT_H

#include "verifExistence.h"
#include "inode.h"
#include "vg.h"
#include "mywrite.h"
#include "myopen.h"
#include "variable_environnement.h"

int mycreate(char *fichier,mode_t mode);

#endif
