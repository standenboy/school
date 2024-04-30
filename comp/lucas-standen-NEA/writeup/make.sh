#!/bin/bash
for i in $(ls | grep .ms); do groff -ms $i -T html > $(echo $i | cut -f1 -d".").html;  done
