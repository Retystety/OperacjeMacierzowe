mecierze.o : macierze.c
	gcc -c macierze.c
	
OperacjeMacierzowe.o : OperacjeMacierzowe.c
	gcc -c OperacjeMacierzowe.c

funTabTekst.o : funTabTekst.c
	gcc -c funTabTekst.c
	
macierze.x : macierze.o OperacjeMacierzowe.o funTabTekst.o
	gcc -o macierze.x macierze.o OperacjeMacierzowe.o funTabTekst.o
