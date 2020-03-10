cmake_minimum_required(VERSION 3.15)
project(ASM C ASM)
set_source_files_properties(foo.s PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")

set(CMAKE_C_STANDARD 11)

add_executable(ASM main.c main_asm.asm)