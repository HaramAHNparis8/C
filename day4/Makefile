CC=gcc

complex:	main.o complex.o complex.h
		$(CC) main.o complex.o -o complex -lm

main.o:		main.c tp4.c

complex.o:	tp4.c complex.h

clean:
	@rm -f *.o
	@rm -f core
	@rm -f *~
