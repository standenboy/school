all:
	zpy raylib_example.zpy -o raylib_example -f -lraylib -f -lm -i raylib.h 
	zpy spaceinvaders.zpy -o spaceinvaders -f -lraylib -f -lm -i raylib.h 
	zpy fib_example.zpy -o fib_example -f -ggdb
	zpy str_example.zpy -o str_example -f -ggdb

	zpy syntaxerr.zpy -o syntaxerr
clean:
	rm -rf fib_example raylib_example str_example spaceinvaders tmp.zpy.c
