#!/bin/sh
./zpy $1 | cc -x c - -Wno-implicit -Wno-builtin-declaration-mismatch -o $2
