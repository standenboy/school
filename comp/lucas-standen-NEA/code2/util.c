#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void die(char *msg){
	fprintf(stderr, "zpy: %s\n", msg);
	exit(1);
}
