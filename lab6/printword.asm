section .text
	global printword
	
extern printLine

printword:
	mov 	ebp, esp
	push	ebp
	xor	ecx, ecx
	
for:
	mov	edx, [ebp+8]; defines SYMBOL_HEIGHTS
	mov	edx, [edx]
	push	ecx; push line num
	mov	eax, ebp
	add	eax,8
	push 	eax; push argc
	mov	eax, ebp
	add 	eax,12
	push 	eax; push argv
	call	printLine
	inc	ecx
	cmp	edx, ecx; ecx=line
	jne	for
	add	esp, 12
	ret
