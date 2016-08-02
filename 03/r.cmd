@echo off
set NAME=cpp3
pdflatex --shell-escape %NAME%.tex
pdflatex --shell-escape %NAME%.tex
del *.dvi
del *.ps
del *.log
del *.aux
del *.out
del *.nav
%NAME%.pdf