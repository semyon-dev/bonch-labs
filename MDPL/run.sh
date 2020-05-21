#!/bin/bash
echo 'Какую лабу запусить?'
echo 'Доступны: 1, 2'
echo '-----------------------------'
read lab_number
cd "lab$lab_number"
echo '-----------------------------'
echo 'Под какую архитектуру скомпилировать и запустить?'
echo '1 - 32bit (только 1 лаба)'
echo '2 - 64bit'
echo '-----------------------------'
read choice
echo '-----------------------------'
case ${choice} in
    1)
        gcc -m32 -fPIE main.c -c -o main.o
        nasm -f elf main_asm.asm -o main_asm.o
        gcc -m32 main.o main_asm.o -o bin32
        rm main.o main_asm.o
        ${PWD}/bin32
        echo '-----------------------------'
        echo 'Скомпилированный бинарник: bin32'
        ;;
    2)
        gcc -no-pie -m64 main.c -c -o main.o
        nasm -f elf64 main_asm.asm -o main_asm.o
        gcc -no-pie -m64 main.o main_asm.o -o bin64
        rm main.o main_asm.o
        ${PWD}/bin64
        echo '-----------------------------'
        echo 'Скомпилированный бинарник: bin64'
        ;;
    *)
        echo 'Такого варианта нет'
       ;;
esac