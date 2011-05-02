## User interface, just set the main filename and it will so everything for you
# This should work as long as you have all the .tex, .sty and .bib files in
# the same folder.
MAINFILE = report
EXTRA_FILES := $(shell echo "AVRJukebox/*.c") $(shell echo "AVRJukebox/*.h")

## Inner workings
OBJECTS = $(shell echo *.tex)
STYLES = $(shell echo *.sty)
BIB = $(shell echo *.bib)

OBJECTS_TEST = $(addsuffix .t, $(basename $(OBJECTS)))
STYLES_TEST = $(addsuffix .s, $(basename $(STYLES)))
BIB_TEST = bib
TESTS = $(addprefix make/, $(OBJECTS_TEST) $(STYLES_TEST) $(BIB_TEST))
TEMP2 := $(shell mkdir make 2>/dev/null)

.PHONY: all
all: $(MAINFILE).dvi $(MAINFILE).pdf

$(MAINFILE).dvi: $(TESTS) $(EXTRA_FILES)
	latex $(MAINFILE)
	latex $(MAINFILE)

$(MAINFILE).pdf: $(TESTS) $(EXTRA_FILES)
	pdflatex $(MAINFILE)
	pdflatex $(MAINFILE)

make/%.t: %.tex
	touch $@

make/%.s: %.sty
	touch $@

make/bib: $(BIB)
	latex $(MAINFILE)
	bibtex $(MAINFILE)
	touch $@

.PHONY: clean
clean:
	-rm -f *.aux
	-rm -f *.log
	-rm -f *.toc
	-rm -f *.bbl
	-rm -f *.blg
	-rm -f *.out
	-rm -f make/bib

.PHONY: cleanall
cleanall: clean
	-rm -f *.pdf
	-rm -f *.ps
	-rm -f *.dvi
	-rm -rf ./make
