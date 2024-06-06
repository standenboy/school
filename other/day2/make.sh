#!/bin/bash

for i in $(ls | grep .ms); do 
	groff -ms $i -e -Tps > $(echo $i | cut -f1 -d".").ps
	ps2pdf $(echo $i | cut -f1 -d".").ps 
done

if [ "$(tty)" = "/dev/tty1" ]; then 
	ps2ascii workexperience.ps 2> /dev/null | less -N
else
	zathura workexperience.pdf &
fi
