%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc -m32 -g -nostdlib -fno-stack-protector -c -o $@ $<

.PHONY: clean all

all: ahalan

ahalan: start.o main.o ahalan.o puts.o length.o write.o
	ld -melf_i386 -g -o $@ $^

ahalan.o: ahalan.asm
start.o: start.asm
main.o: main.c
puts.o: puts.c
length.o: length.c
write.o: write.asm
clean:
	rm *.o ahalan
