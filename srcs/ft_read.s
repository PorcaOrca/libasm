extern __errno_location
global ft_read
section .text
ft_read:
				; int ft_read(int rdi, void* rsi, size_t rdx);
	mov rax 0	;syscall read different in MACOS
	syscall
	cmp rax, 0
	jl set_error
	ret
set_error:
	neg rax 						;only in linux
	push rax						;push error number to the stack
	call __errno_location wrt ..plt ;call external function that set in rax errno ptr
	pop qword [rax]					;get from the stack errno value and put it into errno ptr
	mov rax, -1						;set return
	ret								;gg no re

