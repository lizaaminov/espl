%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc -m32 -g -nostdlib -fno-stack-protector -c -o $@ $<

.PHONY: clean all

all: bcmp

bcmp: start.o bcmp.o fclose.o fopen.o length.o puts.o readchar.o main.o
	ld -melf_i386 -g -o $@ $^

start.o: start.asm
bcmp.o: bcmp.c
fclose.o: fclose.asm
fopen.o: fopen.asm
length.o: length.c
puts.o: puts.asm
readchar.o: readchar.asm
main.o: main.c
clean:
	rm *.o ahalan
