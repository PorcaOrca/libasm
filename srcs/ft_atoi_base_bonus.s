global ft_atoi_base
extern ft_strlen
extern malloc
section .text
ft_atoi_base:
	push rsi
	mov rsi, rdi
	call ft_checkbase
	cmp rax, 0
	jl ft_invalid
	xor rax, rax
	pop rsi
	call ft_isspace
	xor r9, r9
	mov r9, rax
	

invalid:
	ret
ft_check_base:
	call ft_strlen
	cmp rax, 0
	je check_base_invalid
check_base_loop:
	xor rcx, rcx
	mov r8, [rsi+rax*8]
	dec rax
	cmp rax, 0
	je check_base_finish
check_base_array_loop:
	cmp [rsc+rcx*8], r8
	je check_base_invalid
	cmp rax, rcx
	inc rcx
	jne check_base_array_loop
	jmp check_base_loop
check_base_invalid:
	mov rax, -1
	ret
check_base_finish
	ret
ft_isspace:
	xor rax, rax
	xor r8, r8
	mov r8, 0x20
isspace_loophead:
	cmp r8, [rsi + rax * 8]
	jne isspace_finish
	inc rax
	jmp isspace_loophead
isspace_finish:
	ret