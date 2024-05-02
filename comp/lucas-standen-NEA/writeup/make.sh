#!/bin/bash
for i in $(ls | grep .ms); do groff -ms $i -T ps > $(echo $i | cut -f1 -d".").ps;  ps2pdf $(echo $i | cut -f1 -d".").ps; done
zathura coverpage.pdf &
