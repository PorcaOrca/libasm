global
		ft_list_size
section .text
ft_list_size:
	xor rax, rax
loophead:
	cmp rdi, 0
	je finish
	inc rax,
	mov rdi, [rdi+8]
	jmp loophead
finish:
	ret