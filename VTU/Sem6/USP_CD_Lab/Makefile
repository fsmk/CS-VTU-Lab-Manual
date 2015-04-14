LATEX = xelatex

manual.pdf: *.tex */*.tex */*.c exercises.tex
	${LATEX} manual.tex
	${LATEX} manual.tex

exercises.tex: .
	ls -1 */*.tex | sed 's/^/\\\input{/' | sed 's/$$/}/' > exercises.tex

.PHONY: clean
clean:
	rm -f *.aux *.log *.toc *.out *.pdf exercises.tex
