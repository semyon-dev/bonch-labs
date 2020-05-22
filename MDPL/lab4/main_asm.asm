SECTION .DATA

    extern my_array
    extern my_array
    extern arr_size

global asmF

asmF:
    ; 1 - RDI (��� windows rcx)
    ; 2 - RSI (��� windows rdx)

   ; mov r13, rdx      ;������� ��������� d (2'��) �  r13
    mov r13, rsi       ;������� ��������� d (2'��) �  r13

	xor r10, r10       ;counter = 0
    xor r8, r8         ;i = 0

    mov r12, [arr_size]  ;��������� ������� �������

    @L1whileIf:        ;����� ������ �����
    cmp r8, r12        ;i == arr_size -> ����� �� �����

    je @L2End

    ;if
    mov rax, 8         ;������ ����������
    xor rsi, rsi       ;��������� ����� *
    mul r8             ;8*i
    mov rbx, my_array  ;��������� ������ �������
	add rax, rbx      ;�������� ������ ������� �� ��������� ��������
    mov rbx, [rax]     ;��������� �������� my_array[i]

    cmp rdi, rbx       ;c <= a[i]
    jg @L3EndIf

	cmp rbx, r13       ;a[i] <= d

    jg @L3EndIf

    inc r10            ;l++

    @L3EndIf:
    inc r8             ; --i
    jmp @L1whileIf     ;������ � ������ �����

    @L2End:            ;����� ����� �����

   mov rax, r10       ;������� ���������� �������
ret