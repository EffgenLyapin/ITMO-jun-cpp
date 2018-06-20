cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
project(Lec5)
#set(SOURCE main.cpp intset.cpp intset.h sortedintset.cpp sortedintset.h unsortedset.h)
set(SOURCE  dyn_array.h main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})
