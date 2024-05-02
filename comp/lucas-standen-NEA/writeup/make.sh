#!/bin/bash
for i in $(ls | grep .ms); do groff -ms $i -T pdf > $(echo $i | cut -f1 -d".").pdf;  done
zathura coverpage.pdf
