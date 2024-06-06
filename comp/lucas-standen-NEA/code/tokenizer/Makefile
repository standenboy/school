tokenizer: parser util tokenizer.c
	cc -O3 tokenizer.c parser.o util.o -o tokenizer -ggdb
parser: parser.c
	cc -O3 parser.c -c -o parser.o  -ggdb
util: util.c
	cc -O3 util.c -c -o util.o  -ggdb
clean:
	rm -rf *.o
	rm -rf tokenizer
	
