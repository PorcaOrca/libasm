global ft_strlen
section .text
ft_strlen:
			mov rax, -1				; rax = -1
loop:
			inc	rax					; rax++
			mov cl, byte [rdi+rax]	; cl = str[rax]
			cmp cl, 0				; find EOS
			jne loop				; if is zero flag not 1 loop
finish:
			ret
