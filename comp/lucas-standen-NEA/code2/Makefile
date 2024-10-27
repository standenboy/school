CC = cc
CFLAGS =-O3

zpy: zpy.c comp.c parser.c tokenizer.c util.c
	${CC} *.c -c ${CFLAGS}
	${CC} *.o -o zpy ${CFLAGS}
	cd stdlib && make	
clean:
	rm -rf zpy *.o *.core sample out stdlib/*.o
	cd stdlib && make clean
	cd examples && make clean

install: zpy
	mkdir -p /usr/local/share/zpylib
	mkdir -p /usr/local/share/zpylib/include
	cp ./zpy /usr/local/bin/zpy

	cd stdlib && make install
	cd zpypkg && make install

example: zpy
	cd examples && make

uninstall: 
	rm /usr/local/bin/zpy
	rm -rf /usr/local/share/zpylib
