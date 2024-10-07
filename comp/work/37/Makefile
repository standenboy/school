rpn: rpn.c stack.c
	cc stack.c -c -o stack.o
	cc rpn.c stack.o -o rpn -lm -ggdb
clean:
	rm -rf rpn stack.o
