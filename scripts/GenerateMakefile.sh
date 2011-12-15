#!/bin/bash

TEX=pdflatex

rm Makefile

echo -n "all: " >> Makefile
for FILE in *.tex
do echo -n "$(echo "$FILE " | grep -v '*' | sed 's/\.tex/.pdf/')" >> Makefile
done
echo >> Makefile

echo '%.pdf: %.tex' >> Makefile
echo -en "\t" >> Makefile

if [[ $1 != *m* ]]
then echo "$TEX -shell-escape $<" >> Makefile
else echo "(( $TEX -shell-escape $< || ( rm \$@ && false )) && $TEX -shell-escape $< || ( rm \$@ && false )) && $TEX -shell-escape $<" >> Makefile
fi

echo >> Makefile
echo "clean:" >> Makefile
echo -en "\t" >> Makefile
echo 'rm -vf *.aux *.log *.nav *.out *.snm *.toc *.tmp *.tns *.pyg *.vrb *.orig' >> Makefile
