# abbreviation of lab name
LAB = uspcd

# latex command
LATEX = xelatex	
# basename of list of exercises file
LIST_OF_EXERCISES = exercises
# basename of output pdf to generate
OUTPUTFILE = ${LAB}
# list of exercise directories
LIST_OF_EXERCISE_DIRECTORIES = $(wildcard */)

# The output manual
# Depends on
# * main manual file ${OUTPUTFILE}.tex
# * all individual exercise files */*.tex
# * all source files */*.c and */*.cc
# * automatically generated list of all exercises exercises.tex
${OUTPUTFILE}.pdf: ${OUTPUTFILE}.tex */*.tex */*.c */*.cc ${LIST_OF_EXERCISES}.tex
	${LATEX} ${OUTPUTFILE}.tex
	${LATEX} ${OUTPUTFILE}.tex

# List of exercises to be included into the manual
# Automatically generated from the individual exercise tex files
# Depends on the directories in the current directory,
# 	each directory corresponding # 	to one exercise
${LIST_OF_EXERCISES}.tex: ${LIST_OF_EXERCISE_DIRECTORIES}
	ls -1 */*.tex | sed 's/^/\\\input{/' | sed 's/$$/}/' > ${LIST_OF_EXERCISES}.tex

# Clean all generated output files
.PHONY: clean
clean:
	rm -f *.aux *.log *.toc *.out *.pdf exercises.tex
