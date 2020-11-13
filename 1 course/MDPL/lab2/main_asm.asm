SECTION .DATA

extern a_sig
extern b_sig

extern a_unsig
extern b_unsig

extern x_return

global signedF, unsignedF

;       signed
;;;;;;;;;;;;;;;;;;;;;;;;
;a == b
signed_s1:
	mov ax, -1d
	mov [x_return], ax
ret

;a > b
; a*b-1  если a > b
signed_s2:
    mov bx, [b_sig]
    mov ax, [a_sig]
    imul bx
    sub ax, 1d
    mov [x_return], ax
ret

;a < b
; a/b+2 , если a < b
signed_s3:
    mov ax, [a_sig]
	mov bx, [b_sig]
	;cwd ; преобразовать слово, находящееся в регистре АХ, в двойное слово — регистры < DX:AX >).
	mov [x_return], ax
	idiv bx
	mov dx, 2d
	add ax, dx
	mov [x_return], ax
ret

signedF:
	mov ax, [a_sig]
	mov bx, [b_sig]

	cmp ax, bx
	je signed_s1 ;ax==bx
    jg signed_s2 ;ax>bx
	jl signed_s3 ;ax<bx

;       unsigned
;;;;;;;;;;;;;;;;;;;;;;;;
;a == b
unsigned_s1:
	mov ax, -1d
	mov [x_return], ax
ret

;a > b
; a*b-1  если a > b
unsigned_s2:
    mov bx, [b_unsig]
    mov ax, [a_unsig]
	mul bx
	sub ax, 1d
	mov [x_return], ax
ret

;a < b
; a/b+2 , если a < b
unsigned_s3:
	mov ax, [a_unsig]
	mov bx, [b_unsig]
	div bx
	mov dx, 2d
	add ax, dx
	mov [x_return], ax
ret

unsignedF:
	mov ax, [a_unsig]
	mov bx, [b_unsig]

	cmp ax, bx
	je unsigned_s1 ; ax==bx
    jg unsigned_s2 ; ax>bx
	jl unsigned_s3 ; ax<bx
