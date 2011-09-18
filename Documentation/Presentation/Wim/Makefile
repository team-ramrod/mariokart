IMAGES += $(patsubst %.dot,%.pdf,$(wildcard images/*.dot))


%.pdf: %.dot
	dot -Tps2 $< | pstopdf -i -o $@

all: $(IMAGES)
	pdflatex presentation
	pdflatex presentation
