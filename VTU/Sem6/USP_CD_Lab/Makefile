LATEX = xelatex

manual.pdf: *.tex */*.tex */*.c
	${LATEX} manual.tex

.PHONY: clean
clean:
	rm -f *.aux *.log *.toc *.out *.pdf
