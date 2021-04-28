section .data
section .text
	global ft_strcmp
ft_strcmp:
	mov rcx, -1		; init counter
	xor rax, rax	; zeroed rax
	xor r8, r8		; zeroed r8
loophead:
	inc rcx					;increment counter
	mov al, byte[rdi+rcx]	;move in rax s1[rcx]
	mov r8b, byte[rsi+rcx]	;move in r8 s2[rcx]
	cmp al, 0				;check end of s1
	je finish
	cmp r8b, 0				;check end of s2
	je finish
	cmp al, r8b				;compare s1[rcx] s2[rcx]
	je loophead
finish:
	sub al, r8b				; store return in rax
	ret