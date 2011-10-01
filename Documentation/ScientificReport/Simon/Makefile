all: build view

build: 
	latexmake report

clean:
	latexmk -c report

cleanall:
	latexmk -C report

view:
	evince report.pdf -f

.PHONY: clean all view cleanall
