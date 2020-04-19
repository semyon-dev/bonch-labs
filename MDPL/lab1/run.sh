#!/bin/bash
echo 'Под какую архитектуру скомпилировать и запустить?'
echo '1 - 32bit'
echo '2 - 64bit'
echo '-------------'
read choice
case ${choice} in
    1)
        gcc -m32 -fPIE main.c -c -o main.o
        nasm -f elf main_asm.asm -o main_asm.o
        gcc -m32 main.o main_asm.o -o bin32
        rm main.o main_asm.o
        ./bin32
        echo '-------------'
        echo 'Скомпилированный бинарник: bin32'
        ;;
    2)
        gcc -no-pie -m64 main.c -c -o main.o
        nasm -f elf64 main_asm.asm -o main_asm.o
        gcc -no-pie -m64 main.o main_asm.o -o bin64
        rm main.o main_asm.o
        ./bin64
        echo '-------------'
        echo 'Скомпилированный бинарник: bin64'
        ;;
    *)
        echo 'Такого варианта нет'
       ;;
esac