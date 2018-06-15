#ifndef PATH_H
#define PATH_H

typedef struct 
{
	char *chemin;
	char *nom;
}Path;

Path path(char* arg, int provenance);
Path separer(char* arg);

#endif
