all:
	pdflatex -draftmode -interaction=nonstopmode -file-line-error report
	bibtex report
	pdflatex -draftmode -interaction=batchmode report
	pdflatex -interaction=batchmode report

clean:
	rm -rf ./report.aux ./report.bbl ./report.blg ./report.log ./report.out

.PHONY: clean
