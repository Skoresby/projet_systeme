
#include "bash.h"
#include "variable_environnement.h"

extern Inode *tabInode;
extern int nbInode;
extern VE VAR_E;


int mycreate(char *fichier,mode_t mode)
{
	int fd =-1;
	Path recup =path(fichier,3);
	
	printf("le chemein est %s \n",recup.chemin);
	fd=open(fichier,O_WRONLY | O_CREAT | O_APPEND,mode);
	
	if(fd==-1)
	{
		perror("open");
	}
	
	close(fd);
	return fd;

}

