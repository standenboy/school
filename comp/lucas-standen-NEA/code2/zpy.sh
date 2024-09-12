#!/bin/sh
CC=cc
./zpy $1 | ${CC} -O3 -x c - -Wno-implicit -Wno-missing-declarations -o $2
