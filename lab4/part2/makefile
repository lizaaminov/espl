calc: calc.o atod.o
	gcc -o calc calc.o atod.o
calc.o: calc.c
	gcc -c -o calc.o calc.c
atod.o: atod.c
	gcc -c -o atod.o atod.c
	gcc -c -m32 -S -masm=intel atod.c

%.o: %.asm
	nasm -g -f elf -o

