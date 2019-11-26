cgol: cgol.c
	gcc -ansi -Wall -o cgol cgol.c
dynCGOL: dynCGOL.c
	gcc -ansi -Wall -c dynCGol dynCGOL.c

all: cgol.c dynCGOL.c
	gcc -ansi -Wall -o cgol cgol.c
	gcc -ansi -Wall -o dynCGol dynCGOL.c
clean: 
	rm cgol 
	rm dynCGOL
	
