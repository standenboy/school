#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int isIn(char str1[], char str2[]){
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);
	
	for (int i = 0; i < str1Length; i++){
		for (int j = 0; j < str2Length; i++){
			if (str1[i] == str2[j]){
				return 0;
		}
	}
}

int main(){
	
}
