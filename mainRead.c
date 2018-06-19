#include <stdio.h>
#include <stdlib.h>

#include "myread.h"

int main(int argc, char* argv[])
{	
	int a=atoi(argv[1]);
	int b=atoi(argv[3]);
	myread(a,argv[2],b);
	return 0;
}
