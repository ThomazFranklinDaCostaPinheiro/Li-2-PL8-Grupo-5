cmake_minimum_required(VERSION 3.15)
project(Bot C)

set(CMAKE_C_STANDARD 99)

add_executable(Bot main.c logica.c logica.h dados.c dados.h interface.c interface.h listas.c listas.h)