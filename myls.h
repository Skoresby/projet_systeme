#ifndef MYLS_H
#define MYLS_H

#include "vg.h"
#include "verifExistence.h"
#include "verifType.h"
#include "myread.h"
#include "path.h"
#include "liste_chainee.h"


void myls (char *argv[]);
void affiche_ls(char *repertoire, _Bool option);

#endif
