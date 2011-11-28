section .text
global atod
atod:
	push ebp
	mov ebp, esp
	xor edx, edx

.START:

	mov eax, [ebp+8]
	mov eax, [eax]
	test al, al
	je .END
	movzx eax, al
	sub eax, '0'
	mul edx, 10
	add edx eax
	add DWORD [ebp+8], 1
	jmp .START
.END:
	pop ebp
	ret


	
