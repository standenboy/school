#!/bin/sh
zpy ./main.zpy -c -o main.c
zpy ./helloworld.zpy -c -o helloworld.c
cc main.c helloworld.c /usr/local/share/zpylib/zpylib.o -o main -I/usr/local/share/zpylib/include -Wno-implicit-function-declaration
