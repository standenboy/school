#!/bin/sh
zpy ./main.zpy -c -o main.c -i raylib.h
cc main.c /usr/local/share/zpylib/zpylib.o -o main -I/usr/local/share/zpylib/include -Wno-implicit-function-declaration -lraylib -lm
rm -rf main.c
