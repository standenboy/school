all: tokenizer parser
	$(info done tokenizer!)	
tokenizer: tokenizer.c
	cc tokenizer.c -c -o tokenizer.o
parser: parser.c
	cc parser.c -c -o parser.o
clean:
	rm -rf *.o
	
