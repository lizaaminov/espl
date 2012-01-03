%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc -m32 -g -nostdlib -fno-stack-protector -c -o $@ $<

.PHONY: clean all

all: asmart

asmart: asmart.o prsym.o font.o length.o puts.o write.o printword.o
	ld -melf_i386 -g -o $@ $^

prsym.o: prsym.c
asmart.o: asmart.asm
font.o: font.c
length.o: length.c
puts.o: puts.c
write.o: write.asm
printword.o: printword.asm


clean:
	rm *.o asmart
