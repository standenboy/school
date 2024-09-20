CC = cc
CFLAGS = -O0 -ggdb

all: 
	${CC} *.c -c ${CFLAGS}
	${CC} *.o -o zpy ${CFLAGS}
	cd stdlib && make	
clean:
	rm -rf zpy *.o *.core sample out stdlib/*.o
	cd stdlib && make clean

install: all 
	mkdir -p /usr/local/share/zpylib
	mkdir -p /usr/local/share/zpylib/include
	cp ./zpy /usr/local/bin/zpy

	cd stdlib && make install

uninstall: 
	rm /usr/local/bin/zpy
