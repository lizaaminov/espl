
bfix: bfix.o
	gcc -o bfix diff.o bfix.o

bfix.o: bfix.c diff.o
	gcc -c -o bfix.o bfix.c

diff.o: diff.c
	gcc -c -o diff.o diff.c

clean:
	rm *.o
	rm bfixo bfix.c