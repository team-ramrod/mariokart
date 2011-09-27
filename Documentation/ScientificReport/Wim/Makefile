all:
	pdflatex -interaction=nonstopmode -file-line-error report
	bibtex report
	pdflatex -interaction=nonstopmode -file-line-error report
	pdflatex -interaction=batchmode report
