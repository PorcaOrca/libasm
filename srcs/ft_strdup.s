extern malloc
extern ft_strlen
extern ft_strcpy
global ft_strdup
section .text
ft_strdup:
	call ft_strlen 		;find len of argument
	push rdi			;push rdi to stack
	mov rdi, rax		;put len into 1 arg
	call malloc	wrt ..plt		;allocate len memory
	cmp rax, 0			;control on malloc
	je set_error		;error found
	pop rsi				;recover str ptr in 2 arg
	mov rdi, rax		;store dest ptr in 1 arg
	call ft_strcpy		;copy the string
	ret
set_error:
	pop rdi
	ret