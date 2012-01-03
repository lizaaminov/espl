section	.text
	global write

write:					;void write()
	push	ebp
	mov	ebp, esp
	mov edx,	[ebp+16] 
	mov ecx,	[ebp+12] ;message to write
	mov ebx, [ebp+8] ;length
	
	;mov	ebx,1	;file descriptor (stdout)
	mov	eax,4	;system call number (sys_write)
	int	0x80	;call kernel
	pop ebp
	ret

