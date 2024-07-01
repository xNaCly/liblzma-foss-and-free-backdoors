all: main biber

biber: main
	biber liblzma-foss-and-free-backdoors

non-silent:
	pdflatex -shell-escape -jobname=liblzma-foss-and-free-backdoors main 

main:
	pdflatex -interaction=batchmode -shell-escape -jobname=liblzma-foss-and-free-backdoors main 

clean:
	rm -fr \
		*.toc \
		**/**.aux \
		*.aux \
		*.nav \
		*.out \
		*.snm \
		*.toc \
		*.log \
		*.bbl \
		*.blg \
		*.bcf \
		*.run.xml
