#!/bin/bash

for f in ../problems/*/analysis/*.{mp,png,eps} ; do
  cp -v "$f" .
done
pdflatex slides.tex
for f in ../problems/*/analysis/*.{mp,png,eps} ; do
  rm -v $( basename "$f" )
done
