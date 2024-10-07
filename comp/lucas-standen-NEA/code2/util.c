#include <stdlib.h>
#include <stdio.h>

//# a simple die function to bring down the program in the case of an error
void die(char *msg){
	fprintf(stderr, "zpy: %s\n", msg);
	exit(1);
}
