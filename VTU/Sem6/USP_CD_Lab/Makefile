LATEX = xelatex

manual.pdf: *.tex */*.tex */*.cc
	${LATEX} manual.tex

.PHONY: clean
clean:
	rm -f *.aux *.log *.toc *.out *.pdf
