CC=cc
CLFAGS=-O0 -ggdb

stdlib:
	cd String && make
	${CC} *.c -c ${CFLAGS}

clean:
	rm -rf *.o
	cd String && make clean

install:
	cp *.o /usr/local/share/zpylib/
	cp *.h /usr/local/share/zpylib/include/
	cp String/String.o /usr/local/share/zpylib
	cp String/String.h /usr/local/share/zpylib/include

