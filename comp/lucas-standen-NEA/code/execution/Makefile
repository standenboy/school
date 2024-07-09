all: exec builtin vars
	$(info done execution!)
exec: exec.c builtin vars
	cc exec.c builtin.o vars.o ../tokenizer/tokenizer.o ../global/util.o -o exec -ggdb
builtin: builtin.c
	cc builtin.c -c -o builtin.o -ggdb
vars: vars.c
	cc vars.c -c -o vars.o -ggdb
clean:
	rm -rf *.o exec
