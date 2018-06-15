#include <stdlib.h>
#include <stdio.h>
#include "myclose.h"

int main (int argc, char **argv)
{
	int a = myclose(atoi(argv[1]));  
	return a;
}
