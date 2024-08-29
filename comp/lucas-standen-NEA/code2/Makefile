CFLAGS= -O3 

all: _zpy _parser _tokenizer _util _debug
	cc zpy.o parser.o tokenizer.o util.o debug.o -o zpy ${CFLAGS}

_zpy: zpy.c
	cc zpy.c -c -o zpy.o ${CFLAGS}
_parser: parser.c
	cc parser.c -c -o parser.o ${CFLAGS}
_tokenizer: tokenizer.c
	cc tokenizer.c -c -o tokenizer.o ${CFLAGS}
_util: util.c
	cc util.c -c -o util.o ${CFLAGS}

_debug:
	cc debug.c -c -o debug.o ${CFLAGS}

clean:
	rm -rf zpy *.o
