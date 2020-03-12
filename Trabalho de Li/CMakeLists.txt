cmake_minimum_required(VERSION 3.15)
project(Trabalho_de_Li C)

set(CMAKE_C_STANDARD 99)

add_executable(Trabalho_de_Li main.c cmake-build-debug/Dados.c cmake-build-debug/Dados.h cmake-build-debug/Lógica.c cmake-build-debug/Lógica.h cmake-build-debug/Interface.c cmake-build-debug/Interface.h)