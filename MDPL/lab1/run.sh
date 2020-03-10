#!/usr/bin/env bash
gcc -m32 -fPIE main.c -c -o bin/main.o
nasm -f elf main_asm.asm -o bin/main_asm.o
gcc -m32 bin/main.o bin/main_asm.o -o bin/run
bin/run