; Define variables in the data section
SECTION .DATA
    extern au8, bu8, cu8
    extern au16, bu16, cu16
    extern a8, b8, c8
    extern a16int, b16int, c16int;
	extern chisl
	extern znam
	extern res

global uint8, int8, uint16, int16

; (-74/a+c-5)/(1+c*b/2)
uint8:
    push ax
    push dx
    push bx

; --- числитель ---
	mov ax, 0
	mov dx, 0
	mov bx, 0

; -74/a
	mov ax, -74d
	mov bx, [au8]
	cwd
	idiv bx
    mov [chisl], ax

; +c
    mov bx, 0
    mov bl, [cu8]
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

	mov al, [bu8]
	mov bx, 2d
	idiv bx
    mov [znam], ax

; c*
	mov al, [cu8]
    imul ax
    mov [znam], ax

;1+
    inc ax
    mov [znam], ax

; ------ деление (результат) ------
; chisl/znam
;
    mov ax, 0
    mov bx, 0
    mov dx, 0

    mov ax, [chisl]
    mov bx, [znam]
    cwd
    idiv bx
    mov [res], ax

    pop bx
    pop dx
    pop ax
ret

; (-74/a+c-5)/(1+c*b/2)
uint16:
    push ax
    push dx
    push bx

; --- числитель ---
	mov ax, 0
	mov dx, 0
	mov bx, 0

; -74/a
	mov ax, -74d
	mov bx, [au16]
	cwd
	idiv bx
    mov [chisl], ax

; +c
    mov bx, 0
    mov bl, [cu16]
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

	mov al, [bu16]
	mov bx, 2d
	idiv bx
    mov [znam], ax

; c*
	mov al, [cu16]
    imul ax
    mov [znam], ax

;1+
    inc ax
    mov [znam], ax

; ------ деление (результат) ------
; chisl/znam
;
    mov ax, 0
    mov bx, 0
    mov dx, 0

    mov ax, [chisl]
    mov bx, [znam]
    cwd
    idiv bx
    mov [res], ax

    pop bx
    pop dx
    pop ax
ret

; (-74/a+c-5)/(1+c*b/2)
int16:
    push ax
    push dx
    push bx

; --- числитель ---
	mov ax, 0
	mov dx, 0
	mov bx, 0

; -74/a
	mov ax, -74d
	mov bx, [a16int]
	cwd
	idiv bx
    mov [chisl], ax

; +c
    mov bx, 0
    mov bl, [c16int]
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

	mov al, [b16int]
	mov bx, 2d
	idiv bx
    mov [znam], ax

; c*
	mov al, [c16int]
    imul ax
    mov [znam], ax

;1+
    inc ax
    mov [znam], ax

; ------ деление (результат) ------
; chisl/znam
;
    mov ax, 0
    mov bx, 0
    mov dx, 0

    mov ax, [chisl]
    mov bx, [znam]
    cwd
    idiv bx
    mov [res], ax

    pop bx
    pop dx
    pop ax
ret

; (-74/a+c-5)/(1+c*b/2)
int8:
    push ax
    push dx
    push bx

; --- числитель ---
	mov ax, 0
	mov dx, 0
	mov bx, 0

; -74/a
	mov ax, -74d
	mov bx, [a8]
	cwd
	idiv bx
    mov [chisl], ax

; +c
    mov bx, 0
    mov bl, [c8]
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

	mov al, [b8]
	mov bx, 2d
	idiv bx
    mov [znam], ax

; c*
	mov al, [c8]
    imul ax
    mov [znam], ax

;1+
    inc ax
    mov [znam], ax

; ------ деление (результат) ------
; chisl/znam
;
    mov ax, 0
    mov bx, 0
    mov dx, 0

    mov ax, [chisl]
    mov bx, [znam]
    cwd
    idiv bx
    mov [res], ax

    pop bx
    pop dx
    pop ax
ret