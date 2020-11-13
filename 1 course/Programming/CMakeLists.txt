cmake_minimum_required(VERSION 3.15)
project(Programming C)
set(CMAKE_C_STANDARD 11)
# здесь укажите папку и файл(ы) для запуска нужной лабы
add_executable(Programming lab12 lab12/lab12.c)
target_link_libraries(Programming m)