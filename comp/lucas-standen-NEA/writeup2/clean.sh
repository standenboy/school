#!/bin/bash
shopt -s extglob

rm -rf !(*.tex|*.sh|ref.bib)
