CC=cc
CFLAGS=-O3

stdlib:
	cd String && make
	${CC} zpylib.c -c -o zpylib.o  ${CFLAGS}

clean:
	rm -rf *.o
	cd String && make clean

install:
	cp *.o /usr/local/share/zpylib/
	cp *.h /usr/local/share/zpylib/include/
	cp String/String.o /usr/local/share/zpylib
	cp String/String.h /usr/local/share/zpylib/include

