CC=cc
CFLAGS=-O3

SRC = zpylib.c
OBJ = ${SRC:.c=.o}


all:
	${CC} -c ${SRC} -o ${OBJ} ${CFLAGS}
	cd String && make
install: all 
	mkdir -p /usr/local/share/zpylib
	cp zpylib.o /usr/local/share/zpylib/
	
	mkdir -p /usr/local/share/zpylib/include
	cp zpylib.h /usr/local/share/zpylib/include/
	cd String && make install
clean:
	rm -rf *.o
	cd String && make clean
uninstall: 
	rm -rf /usr/local/share/zpylib

.PHONY: all clean install uninstall
