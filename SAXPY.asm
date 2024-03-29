section .data

invalid_input db "Invalid input: n must be greater than 0", 10, 0
test_str db "RCX is %d", 10, 0

section .text
bits 64
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
	; ecx = n, xmm0 = A, rdx = *X, r8 = *Y
        
	mov rdx, rcx

	; allocate memory for Z
	sub rsp, 8*5
	call malloc
	add rsp, 8*5
	mov rdi, rax ; store the returned pointer

	mov rax, 0 ; i = 0

LOOP:
	movsd xmm1, [rdx + rax*8] ; xmm1 = X[i]
	mulsd xmm1, xmm0 ; xmm1 = A * X[i]
	addsd xmm1, [r8 + rax*8] ; xmm1 = A * X[i] + Y[i]
	movsd [rdi + rax*8], xmm1 ; Z[i] = A * X[i] + Y[i]

	inc rax
	loop LOOP

	; return Z
	mov rax, rdi
	ret
