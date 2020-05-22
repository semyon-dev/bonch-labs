;.686
;.model flat, c

SECTION .DATA

extern a_f
extern b_f
extern result_f
extern c_i

global ASMCalc

; 17 (-74/a+c-5)/(1+c*b/2)

ASMCalc:
	;вторая часть
    fild dword [c_i]    ; загрузка в вершину стека

    fmul dword [b_f]        ;c*b

	mov eax, 2d
    push eax
	fild dword [esp]
	pop eax
	fdiv            ;[c*b] / 2

	mov eax, 1d
    push eax
    fild dword [esp]
	pop eax
	fadd  ; 1+

	fstp dword [result_f]

    ; (-74/a+c-5)
	;первая часть
	mov eax, -74d
	push eax
	fild dword [esp]
	pop eax

	fdiv dword [a_f]  ; -74/a

	fild dword [c_i]
	fadd         ; + c

	mov eax, 5d
    push eax
    fild dword [esp]
    pop eax
	fsub  ; -5

	fdiv dword [result_f]
	fstp dword [result_f]
ret
