section .text
	  global fopen

fopen: 
	  push ebp
	  mov ebp, esp
	  mov edx,0 
	  mov ebx,[esp + 8] 
	  mov ecx,384 
	  mov eax,5 ;system call number (sys_open)
	  int 0x80 ;call kernel
	  pop ebp
	  ret