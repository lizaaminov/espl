section .text
	global puts

extern length 

puts: 
	 push ebp
	 mov ebp, esp
	 push dword [esp + 8] 
	 call length 
	 mov edx,eax 
	 add esp,4 
	 mov dword ecx,[esp + 8] ;message to write
	 mov ebx,1 ;file descriptor (stdout)
	 mov eax,4 ;system call number (sys_write)
	 int 0x80 ;call kernel
	 pop ebp
	 ret

section .data

msg db 'ahalan!',0xa,0 ;our dear string


