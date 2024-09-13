CC = cc
CFLAGS = -O0 -ggdb

all: _zpy _parser _tokenizer _comp _appendsnprintf _util _debug
	${CC} zpy.o parser.o tokenizer.o comp.o appendsnprintf.o util.o debug.o -o zpy ${CFLAGS}

_zpy: zpy.c
	${CC} zpy.c -c -o zpy.o ${CFLAGS}
_parser: parser.c
	${CC} parser.c -c -o parser.o ${CFLAGS}
_tokenizer: tokenizer.c
	${CC} tokenizer.c -c -o tokenizer.o ${CFLAGS}
_comp: comp.c
	${CC} comp.c -c -o comp.o ${CFLAGS}
_appendsnprintf: appendsnprintf.c
	${CC} appendsnprintf.c -c -o appendsnprintf.o ${CFLAGS}
_util: util.c
	${CC} util.c -c -o util.o ${CFLAGS}

_debug:
	${CC} debug.c -c -o debug.o ${CFLAGS}

clean:
	rm -rf zpy *.o *.core sample
