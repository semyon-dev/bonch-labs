SECTION .DATA

    extern my_array
    extern my_array
    extern arr_size

global asmF

asmF:
    ; 1 - RDI (для windows rcx)
    ; 2 - RSI (для windows rdx)

   ; mov r13, rdx      ;перенос параметра d (2'ой) в  r13
    mov r13, rsi       ;перенос параметра d (2'ой) в  r13

	xor r10, r10       ;counter = 0
    xor r8, r8         ;i = 0

    mov r12, [arr_size]  ;получнеие размера массива

    @L1whileIf:        ;метка начала цикла
    cmp r8, r12        ;i == arr_size -> выход из цикла

    je @L2End

    ;if
    mov rax, 8         ;размер переменной
    xor rsi, rsi       ;зануление перед *
    mul r8             ;8*i
    mov rbx, my_array  ;получение адреса массива
	add rax, rbx      ;сложение адреса массива со смещением элемента
    mov rbx, [rax]     ;получение значения my_array[i]

    cmp rdi, rbx       ;c <= a[i]
    jg @L3EndIf

	cmp rbx, r13       ;a[i] <= d

    jg @L3EndIf

    inc r10            ;l++

    @L3EndIf:
    inc r8             ; --i
    jmp @L1whileIf     ;прыжок в начало цикла

    @L2End:            ;метка конца цикла

   mov rax, r10       ;возврат результата функции
ret