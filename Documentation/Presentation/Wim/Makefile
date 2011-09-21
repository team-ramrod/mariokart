IMAGES += $(patsubst %.dot,%.pdf,$(wildcard images/*.dot))
IMAGES += $(patsubst %.gif,%.png,$(wildcard images/*.gif))

%.png: %.gif
	convert $< $@

%.pdf: %.dot
	dot -Tps2 $< | pstopdf -i -o $@

all: $(IMAGES)
	pdflatex presentation
	pdflatex presentation
