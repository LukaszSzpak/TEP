cmake_minimum_required(VERSION 3.15)
project(Lista4)

set(CMAKE_CXX_STANDARD 98)

add_executable(Lista4 main.cpp CFileLastError.cpp CFileLastError.h CFileThrowEx.cpp CFileThrowEx.h CFileErrCode.cpp CFileErrCode.h Zakres.cpp Zakres.h)
