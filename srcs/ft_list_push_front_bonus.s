extern malloc
global
	ft_list_push_front
section .text
ft_list_push_front:
	xor rax, rax					;void	push_front(t_list **lst_ptr, void *data)
	push rdi						;push list to stack
	push rsi						;push data into stack
	mov rdi, 16
	call malloc wrt ..plt
	pop rsi
	pop rdi
	cmp rax, 0						;malloc protection
	je finish
	mov [rax], rsi
	mov r8, [rdi]					;insert new element in a list
	mov [rax+8], r8					;
	mov [rdi], rax
finish:
	ret