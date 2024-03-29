section .data

invalid_input db "Invalid input: n must be greater than 0", 10, 0

section .text
default rel
global saxpy_asm
extern printf, malloc
saxpy_asm:
	cmp rcx, 0
	jg CONTINUE

	; Invalid input
	sub rsp, 8*5
	lea rcx, [invalid_input]
	call printf
	add rsp, 8*5
	ret

CONTINUE:
	; Z[i] = A * X[i] + Y[i]
	; ecx = n, xmm1 = A, r8 = *X, r9 = *Y, rsp+32 = *Z
	mov rsi, [rsp+32] ; rsi = *Z

	mov rax, 0 ; i = 0

LOOP:
	movsd xmm0, [r8 + rax*8] ; xmm0 = X[i]
	mulsd xmm0, xmm1 ; xmm0 = A * X[i]
	addsd xmm0, [r9 + rax*8] ; xmm0 = A * X[i] + Y[i]
	movsd [rsi + rax*8], xmm0 ; Z[i] = A * X[i] + Y[i]

	inc rax
	loop LOOP

	; return Z
	mov rax, rdi
	ret
