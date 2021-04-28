extern __errno_location			;___error for macOS
global ft_write
section .text
ft_write:
					; int ft_write(int rdi, const void *rsi, size_t rdx)
	mov rax, 1		;sycall identifier 4 for macos 1 for linux
	syscall
	cmp rax, 0		;look for error
	jl set_error	;jump if lower to the set_error
	ret				;otherwise all good
set_error:
	neg rax							;only in linux
	push rax						;store error value in the stack
	call __errno_location wrt ..plt	;store in rax the *int at the error
	pop qword [rax]					;modify the mmemory value pointed by rax
	mov rax, -1						;set return of function to -1
	ret