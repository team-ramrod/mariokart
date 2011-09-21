IMAGES += $(patsubst %.dot,%.pdf,$(wildcard images/*.dot))
IMAGES += $(patsubst %.gif,%.png,$(wildcard images/*.gif))

%.png: %.gif
	convert $< $@

%.pdf: %.dot
	dot -Tps2 $< | ps2pdf - $@

all: $(IMAGES)
	pdflatex -file-line-error -halt-on-error presentation
	pdflatex presentation
