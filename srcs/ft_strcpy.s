segment .data
segment .text
	global ft_strcpy
ft_strcpy:
	mov rcx, -1
	xor r8, r8
loophead:
	inc rcx
	mov r8b, byte[rsi+rcx]
	mov byte[rdi+rcx], r8b
	cmp r8b, 0
	jne loophead
finish:
	mov rax, rdi
	ret