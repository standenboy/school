CC=cc
CFLAGS=-O3

SRC = zpylib.c
OBJ = ${SRC:.c=.o}

all: zpy 

.c.o:
	${CC} -c ${CFLAGS} $<
	cd String && make
install: all 
	cp zpy /usr/local/bin/zpy
	cd stdlib && make install
	cd zpypkg && make install
clean:
	rm -rf zpy*.o
	cd stdlib && make clean
	cd examples && make clean
uninstall: 
	rm /usr/local/bin/zpy

.PHONY: all clean install uninstall
