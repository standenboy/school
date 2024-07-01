all: exec builtin
	$(info done execution!)
exec: exec.c builtin
	cc exec.c builtin.o ../tokenizer/tokenizer.o ../global/util.o -o exec -ggdb
builtin: builtin.c
	cc builtin.c -c -o builtin.o -ggdb
