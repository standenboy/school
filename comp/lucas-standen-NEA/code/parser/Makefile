all: readfile preprocesor parser
	cc readfile.o preprocessor.o parser.o -o parser 

readfile:
	cc -c readfile.c -o readfile.o
preprocesor: 
	cc -c preprocessor.c -o preprocessor.o
parser: parser.c
	cc -c parser.c -o parser.o

clean:
	rm -rf *.o parser
