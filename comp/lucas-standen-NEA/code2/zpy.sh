#!/bin/sh
CC=cc
warnings="-Wno-builtin-declaration-mismatch -Wno-implicit -Wno-missing-declarations" 
./zpy $1 | ${CC} ${warnings} -x c - -o $2 
