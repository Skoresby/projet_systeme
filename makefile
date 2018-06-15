main1: main1.o
	gcc -o main1 main1.o
main1.o: main1.c
	gcc -o main1.o -c main1.c -W -Wall -ansi -pedantic


clean:
	rm -rf *.o

