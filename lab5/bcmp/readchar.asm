section .text
	  global readchar

readchar: 

	  push ebp
	  mov ebp, esp
	  mov ebx,[esp + 8] 
	  mov ecx,[esp + 12] 
	  mov word edx,1 
	  mov eax,3 ;system call number (sys_read)
	  int 0x80 ;call kernel
	  movzx ecx, cl 
	  pop ebp
	  ret