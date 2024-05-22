tokenizer: parser util tokenizer.c
	cc -O3 tokenizer.c parser.o util.o -o tokenizer
parser: parser.c
	cc -O3 parser.c -c -o parser.o
util:	util.c
	cc -O3 util.c -c -o util.o

clean:
	rm -rf *.o
	rm -rf tokenizer
	
