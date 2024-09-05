#!/bin/sh
./zpy $1 | cc -x c - -Wno-implicit -Wno-missing-declarations -o $2
