#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "./String/String.h"

void printchar(char c){
	putchar(c);
}

void printint(int i){
	printf("%d", i);
}

void printfloat(double f){
	printf("%f", f);
}

char readchar(){
	char c;
	scanf("%c", &c);
	return c;
}

int readint(){
	int i;
	scanf("%d", &i);
	return i;
}

double readfloat(){
	double f;
	scanf("%lf", &f);
	return f;
}

int randint(int lower, int upper){
	srand(time(NULL));
	return rand() % (((upper + 1) - lower) + lower);
}
