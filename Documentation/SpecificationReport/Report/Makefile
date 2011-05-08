default: report.pdf
	if [ -x /usr/bin/open ] ; then /usr/bin/open report.pdf ; fi

report.pdf: $(wildcard *.tex) report.blb
	pdflatex report

report.blb: report.aux report.bib
	bibtex report

report.aux: $(wildcard *.tex)
	pdflatex report

clean:
	-rm -f report.aux
	-rm -f report.out
	-rm -f report.log
	-rm -f report.blg
	-rm -f report.bbl
	-rm -f report.toc
