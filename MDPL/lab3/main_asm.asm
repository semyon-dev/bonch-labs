; Assemble:	  nasm -f elf64 -l main_asm.lst  main_asm.asm
; Link:		  gcc -m64 -o main_asm main_asm.o
; Run:		  ./main_asm

extern printf
extern scanf
extern exit

extern a_sig
extern b_sig
extern a_unsig
extern b_unsig

extern x_return

global main

segment .data

	mode_1_str: db "1 signed",0Dh,0Ah,0
	mode_2_str: db "2 unsigned",0Dh,0Ah,0
	mode_3_str: db "3 exit",0Dh,0Ah,0
	enter_mode_str: db "Enter node: ",0Dh,0Ah,0

	mode_scanf_str: db "%d",0
	mode: dq 0

	enter_a_str: db "a: ", 0
	enter_b_str: db "b: ", 0

	enter_sword: db "%hd",0
	enter_uword: db "%hu",0
	print_sword: db "x: %hd",10,0

	a_sig: dw 0
	b_sig: dw 0

	a_unsig: dw 0
	b_unsig: dw 0

	x_return: dw 0

segment .text

main:
	sub rsp, 28h ; выделяем память в стеке

	@start:
	sub rsp, 8    ; теневая область для printf

	;1 Знаковый\n
	mov rdi, mode_1_str
	mov rax, 0
	call printf

	;2 беззнаковый\n
	mov rdi, mode_2_str
	mov rax, 0
	call printf

	;3 выход\n
	mov rdi, mode_3_str
	mov rax, 0
	call printf

	;Enter mode
	mov rdi, enter_mode_str
	mov rax, 0
	call printf

	add rsp, 8               ;очвобождение теневой области область для printf

	;Enter
	sub rsp, 8*2
	mov rdi, mode_scanf_str
	mov rsi, mode
	mov rax, 0
	call scanf
	add rsp, 8*2

	mov rax, 1
	cmp rax, [mode]
	je @m_1
	mov rax, 2
	cmp rax, [mode]
	je @m_2
	mov rax, 3
	cmp rax, [mode]
	je @next
	jmp @start

@m_1:
	sub rsp, 8*2              ;теневая область для printf
	;a:
	mov rdi, enter_a_str
	call printf

	;enter a
	mov rdi, enter_sword
	mov rsi, a_sig
	call scanf

	;b:
	mov rdi, enter_b_str
	call printf

	;enter b
	mov rdi, enter_sword
	mov rsi, b_sig
	call scanf

	call signedF

	;print x
	mov rdi, print_sword
	mov si, [x_return]
	call printf

	add rsp, 8*2
	jmp @start
@m_2:
	sub rsp, 8*2              ;теневая область для printf
	;a:
	mov rdi, enter_a_str
	call printf

	;enter a
	mov rdi, enter_uword
	mov rsi, a_unsig
	call scanf

	;b:
	mov rdi, enter_b_str
	call printf

	;enter b
	mov rdi, enter_uword
	mov rsi, b_unsig
	call scanf

	call unsignedF

	;print x
	mov rdi, print_sword
	mov si, [x_return]
	call printf

	add rsp, 8*2
	jmp @start
@next:
	mov esi, 0
	call exit
	ret

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
