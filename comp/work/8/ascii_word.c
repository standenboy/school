#include<stdio.h>
#include<string.h>
int main(){
	char sentence[1000];

	fgets(sentence, 1000, stdin);
	for (int i = 0; i < strlen(sentence) - 1; i++){
		printf("%d \0 ", (int)sentence[i]); 	
	}
	printf("\n");
}
