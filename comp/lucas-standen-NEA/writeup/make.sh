#!/bin/bash

for i in $(ls | grep .ms); do 
	groff -ms $i -e -Tps > $(echo $i | cut -f1 -d".").ps
	ps2pdf $(echo $i | cut -f1 -d".").ps 

	pdftocgen coverpage.pdf < recipe.toml | pdftocio coverpage.pdf
	mv coverpage_out.pdf coverpage.pdf
done

if [ "$(tty)" = "/dev/tty1" ]; then 
	ps2ascii coverpage.ps 2> /dev/null | less -N
else
	zathura coverpage.pdf &
fi
