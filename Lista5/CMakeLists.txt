cmake_minimum_required(VERSION 3.15)
project(Lista5)

set(CMAKE_CXX_STANDARD 98)

add_executable(Lista5 main.cpp Static/CNodeStatic.cpp Static/CNodeStatic.h Static/CTreeStatic.cpp Static/CTreeStatic.h Dynamic/CNodeDynamic.cpp Dynamic/CNodeDynamic.h Dynamic/CTreeDynamic.cpp Dynamic/CTreeDynamic.h)