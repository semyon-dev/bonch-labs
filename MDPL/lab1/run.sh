#!/usr/bin/env bash
gcc -m32 -fPIE main.c -c -o main.o
nasm -f elf main_asm.asm -o main_asm.o
gcc -m32 main.o main_asm.o -o run
./run