cmake_minimum_required(VERSION 2.8)

project(Lec4)
set(SOURCE main.cpp intset.cpp intset.h sortedintset.cpp sortedintset.h unsortedset.h)
add_executable(${PROJECT_NAME} ${SOURCE})
