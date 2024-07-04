all: tokenizer parser
	$(info done tokenizer!)	
tokenizer: tokenizer.c
	cc tokenizer.c -c -o tokenizer.o -ggdb
parser: parser.c
	cc parser.c -c -o parser.o -ggdb
clean:
	rm -rf *.o
	
