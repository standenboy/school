CC=cc
CFLAGS=-O3

SRC = String.c
OBJ = ${SRC:.c=.o}


all:
	${CC} -c ${SRC} -o ${OBJ} ${CFLAGS}
install: all 
	cp String.o /usr/local/share/zpylib/
	cp String.h /usr/local/share/zpylib/include/
clean:
	rm -rf *.o

.PHONY: all clean install uninstall
