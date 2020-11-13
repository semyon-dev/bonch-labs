#!/bin/bash
echo 'Какую лабу запусить?'
echo 'Доступны: 1, 2, 3, 4, 5'
echo '-----------------------------'
read lab_number
cd "lab$lab_number"
echo '-----------------------------'
case ${lab_number} in
    1)
        echo 'Под какую архитектуру скомпилировать и запустить?'
        echo '1 - 32bit (только 1 лаба)'
        echo '2 - 64bit'
        echo '-----------------------------'
        read choice
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
            esac
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
    3)
        nasm -f elf64 -l main_asm.lst  main_asm.asm
        gcc -no-pie -m64 -o bin64 main_asm.o
    	rm main_asm.o main_asm.lst
        ${PWD}/bin64
        echo '-----------------------------'
        echo 'Скомпилированный бинарник: bin64'
        ;;
    4)
        gcc -no-pie -m64 main.c -c -o main.o
        nasm -f elf64 main_asm.asm -o main_asm.o
        gcc -no-pie -m64 main.o main_asm.o -o bin64
        rm main.o main_asm.o
        ${PWD}/bin64
        echo '-----------------------------'
        echo 'Скомпилированный бинарник: bin64'
        ;;
    5)
        gcc -m32 -fPIE main.c -c -o main.o
        nasm -f elf main_asm.asm -o main_asm.o
        gcc -m32 main.o main_asm.o -o bin32
        rm main.o main_asm.o
        ${PWD}/bin32
        echo '-----------------------------'
        echo 'Скомпилированный бинарник: bin32'
        ;;
    *)
        echo 'Такого варианта нет'
       ;;
esac