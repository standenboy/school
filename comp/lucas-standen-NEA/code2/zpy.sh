#!/bin/sh
CC=cc
./zpy $1 | ${CC} -x c - -Wno-implicit -Wno-missing-declarations -o $2
