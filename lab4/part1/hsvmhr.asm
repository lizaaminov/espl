section .text
global hsvmhr
hsvmhr:
	push	ebp
	mov	ebp, esp
.L5:
	mov	eax, [ebp+8] ; first parameter of function location
	mov	eax, [eax]
	mov	edx, [ebp+12] ; second parameter of function location
	mov	edx, [edx]
	movzx eax, al ; assignment of the first byte in eax
	movzx edx, dl ; assignment of the first byte in edx
	sub	eax, edx ; calculates eax-edx
	je	.L2 ; jumps if equal to L2
	jmp	.L3 ; else jump to L3
.L2:
	test dl, dl ; checks if dl!=0
	jne	.L4 ; if yes jump to l4
	xor	eax, eax ; returns 1 if one of the parameters is 1 else returns 0. eax=0
	jmp	.L3
.L4:
	add	DWORD [ebp+8], 1
	add	DWORD [ebp+12], 1
	jmp	.L5
.L3:
	pop	ebp
	ret
