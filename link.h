#ifndef LINK_H
#define LINK_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "inode.h"
#include "path.h"
#include "liste_chainee.h"
#include "variable_environnement.h"
#include "vg.h"
#include "ln.h"
#include "verifExistence.h"
#include "verifType.h"


void link(Path nom1 ,Path nom2);


#endif
