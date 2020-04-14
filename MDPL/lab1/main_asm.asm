; Define variables in the data section
SECTION .DATA
    extern au8, bu8, cu8
    extern au16, bu16, cu16
    extern a8int, b8int, c8int
    extern a16int, b16int, c16int
	extern chisl
	extern znam
	extern res

global int8, uint8, uint16, int16

; (-74/a+c-5)/(1+c*b/2)
int8:
    push ax
    push dx
    push bx

; --- числитель ---
	mov ax, 0
	mov dx, 0
	mov bx, 0
	mov al, 0
	mov dl, 0

    ;-74/a
	mov ax, -74d        ; -74 -> ax
	mov dl, [a8int]     ; a8int -> dl
	; если делитель размером в байт, то делимое должно быть расположено в регистре ax.
	; После операции частное помещается в al, а остаток — в ah;
	idiv dl   ; ax / dl = al
	cbw       ; (cbw конвертирует al -> ax)
    mov [chisl], ax

   ;+c
    mov bx, 0
    mov al, 0
    mov ax, 0

    mov bx, [chisl]
    mov al, [c8int]
    cbw ; (cbw конвертирует al -> ax)
    add ax, bx
    mov [chisl], ax

 ;-5
    sub ax, 5
    mov [chisl], ax

; ----- знаменатель ------
; b/2
    mov ax, 0
   	mov dx, 0
   	mov bx, 0
   	mov al, 0

	mov al, [b8int]
	cbw   ; (cbw конвертирует al -> ax)
	mov bl, 2d
	idiv bl
	; если делитель размером в байт, то делимое должно быть расположено в регистре ax.
	; После операции частное помещается в al, а остаток — в ah;
	cbw  ; (cbw конвертирует al -> ax)
    mov [znam], ax

 ; c*
    mov ax, 0
    mov bx, [znam]
	mov al, [c8int]
	cbw ; (cbw конвертирует al -> ax)
    imul bx ; если операнд, указанный в команде, — слово, то второй сомножитель располагается в ax;
    ; при умножении слов результат помещается в пару dx:ax;
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
	mov dl, [au8]
	idiv dl   ; ответ (частное) -> al
	cbw       ; (cbw конвертирует al -> ax)
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
    mov ax, 0
    mov bx, [znam]
    mov al, [cu8]
    cbw ; (cbw конвертирует al -> ax)
    imul bx ; если операнд, указанный в команде, — слово, то второй сомножитель располагается в ax;
            ; при умножении слов результат помещается в пару dx:ax;
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

    mov bx, 2d
    mov ax, [bu16]
    cwd        ; преобразовать слово, находящееся в регистре АХ, в двойное слово — регистры DX:AX
    idiv bx
            ; если делитель размером в слово,
            ; то делимое должно быть расположено в паре регистров dx:ax,
            ; причем младшая часть делимого находится в ax.
            ; После операции частное помещается в ax, а остаток — в dx;
    mov [znam], ax

; c*
   	mov bx, 0
	mov bx, [cu16]
    imul bx
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
	cwd ; преобразовать слово, находящееся в регистре АХ, в двойное слово — регистры < DX:AX >).
	mov bx, [a16int]
	idiv bx
	    ; если делитель размером в слово,
        ; то делимое должно быть расположено в паре регистров dx:ax,
        ; причем младшая часть делимого находится в ax.
        ; После операции частное помещается в ax, а остаток — в dx;
    mov [chisl], ax

; +c
    mov bx, 0
    mov bx, [c16int]
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

	mov bx, 2d
	mov ax, [b16int]
	cwd        ; преобразовать слово, находящееся в регистре АХ, в двойное слово — регистры DX:AX
	idiv bx
	        ; если делитель размером в слово,
            ; то делимое должно быть расположено в паре регистров dx:ax,
            ; причем младшая часть делимого находится в ax.
            ; После операции частное помещается в ax, а остаток — в dx;
    mov [znam], ax

    ; c*
   	mov bx, 0
	mov bx, [c16int]
    imul bx
    mov [znam], ax

    ;1+
    inc ax
    mov [znam], ax

; ------ деление (результат) ------

    ;chisl/znam

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