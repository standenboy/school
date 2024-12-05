#!/bin/bash
pdflatex writeup.tex
bibtex writeup.tex
pdflatex writeup.tex
pdflatex writeup.tex

