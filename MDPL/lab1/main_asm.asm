; Define variables in the data section
SECTION .DATA
;	hello:     db 'Hello world!',10
;	helloLen:  equ $-hello
	extern a

global _somefunc

_somefunc:
	mov eax, [a]
	inc eax
    mov [a], eax
;    mov eax,4            ; 'write' system call = 4
;   	mov ebx,1            ; file descriptor 1 = STDOUT
;   	mov ecx,hello        ; string to write
;   	mov edx,helloLen     ; length of string to write
;   int 80h              ; call the kernel
ret