section .data

invalid_input db "Invalid input: n must be greater than 0", 10, 0
;param_list_str db "n = %d, A = %f, X = 0x%x, Y = 0x%x, Z = 0x%x", 10, 0

section .text
default rel
global saxpy_asm
extern printf
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
	; Print the parameters

	;sub rsp, 8*7
	;mov rbx, [rsp+32]
	;mov [rsp+40], rbx ; Z
	;mov [rsp+32], r9 ; Y
	;mov r9, r8 ; X
	;movq r8, xmm1 ; A
	;mov rdx, rcx ; n
	;lea rcx, [param_list_str]
	;call printf
	; restore the parameters
	;mov rcx, rdx ; n
	;mov rdx, r8 ; A
	;mov r8, r9 ; X
	;mov r9, [rsp+32] ; Y
	;mov [rsp+32], rbx ; Z
	;add rsp, 8*7

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
