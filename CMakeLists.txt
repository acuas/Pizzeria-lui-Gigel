cmake_minimum_required(VERSION 3.12)
project(Pizza)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pizza main.cpp Pizza.cpp Pizza.h PizzaMargherita.cpp PizzaMargherita.h Cheesy.cpp Cheesy.h Dracula.cpp Dracula.h)