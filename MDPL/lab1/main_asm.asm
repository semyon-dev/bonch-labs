; Define variables in the data section
SECTION .DATA
	extern a
	extern b
	extern c
	extern chisl
	extern znam
	extern res

global mainA

; (-74/a+c-5)/(1+c*b/2)
mainA:
    push ax
    push dx
    push bx

; --- числитель ---
	mov ax, 0
	mov dx, 0
	mov bx, 0

; -74/a
	mov al, [a]
	mov bx, -74d
	idiv bx
    mov [chisl], ax

; +c
    mov bx, 0
    mov bl, [c]
    add ax, bx
    mov [chisl], ax

; -5
    sub ax, 5
    mov [chisl], ax

; ----- знаменатель ------
; b/2
    mov ax, 0
   	mov dx, 0
   	mov bx, 0

	mov al, [b]
	mov bx, 2d
	idiv bx
    mov [znam], ax

; c*
	mov al, [c]
    imul ax
    mov [znam], ax

;1+
    inc ax
    mov [znam], ax

; ------ деление (результат) ------
; chisl/znam
;
    mov ax, 0
    mov dx, 0
    mov bx, 0
    mov al, 0

    mov al, [chisl]
    mov bl, [znam]
    idiv bx
    mov [res], ax

    pop bx
    pop dx
    pop ax
ret