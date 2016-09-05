cmake_minimum_required(VERSION 3.6)
project(Practica1_OperacionesLenguajes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c language.h mystring.h)
add_executable(Practica1_OperacionesLenguajes ${SOURCE_FILES})