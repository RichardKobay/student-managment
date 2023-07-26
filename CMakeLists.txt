cmake_minimum_required(VERSION 3.25)
project(proyecto_vacacional C)

set(CMAKE_C_STANDARD 11)

add_executable(proyecto_vacacional main.c userManagment.c userManagment.h utils.c utils.h studentManagment.c studentManagment.h)
