#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "./String/String.h"

void printstr(char *s){
	printf("%s", s);
}	

void printchar(char c){
	putchar(c);
}

void printint(int i){
	printf("%d", i);
}

void printfloat(double f){
	printf("%f", f);
}

char *readstr(){
	char *str = calloc(1, 256);
	fgets(str, 256, stdin);
	return str;
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
	return random() % (((upper + 1) - lower) + lower);
}
