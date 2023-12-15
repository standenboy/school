#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char num[8];
	int parity;
	scanf("%s", num);
	char number[8];
	for (int i = 0; i < 8; i++){
		if (i == 7){
			if (num[i] == '1'){
				parity = 1;
			}else{
				parity = 0;
			}	
		}else{
			if (num[i] == '1'){
				number[i] = 1;	
			}else{
				number[i] = 0;	
			}
		}
	}
	int number_of_ones = 0;
	for (int i = 0; i < 8; i++){
		if (number[i] == 1){
			number_of_ones++;
		}
	}
	if (number_of_ones % 2 == parity){
		printf("bad\n");
	}
}
