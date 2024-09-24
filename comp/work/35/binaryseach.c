#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *arr[] = {
	"ali",
	"ben",
	"carl",
	"joe",
	"ken",
	"lara",
	"mo",
	"oli",
	"pam",
	"stan",
	"tara"
};
int len = 11;

char *binsearch(char *tofind){
	int l = len/2;
	char *start = arr[0];
	char *end = arr[len];
	char *mid = arr[l];

	while (mid != tofind){
		if (strcmp(mid, tofind) < 0){
			start = mid;
			l /= 2;
			mid = arr[len - l];
		}else {
			end = mid;
			l /= 2;
			mid = arr[len - l]
		}
	}

	return start;
}

int main(){
	binsearch("pam");
}
