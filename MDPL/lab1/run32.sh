#!/usr/bin/env bash
gcc -m32 -fPIE main.c -c -o bin32/main.o
nasm -f elf main_asm.asm -o bin32/main_asm.o
gcc -m32 bin32/main.o bin32/main_asm.o -o bin32/run
./bin32/run