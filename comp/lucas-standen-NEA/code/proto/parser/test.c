#include <stdio.h>
#include "../../tokenizer/parser.h"

int main(){
	char *buf = parser("sample.zpy");
	printf("%s", buf);
}
