cmake_minimum_required(VERSION 3.17)
project(IUTestTask)

set(CMAKE_CXX_STANDARD 20)

add_executable(IUTestTask main.cpp IntHolder.cpp IntHolder.h BaseHolder.h DoubleHolder.cpp DoubleHolder.h CharArrayHolder.cpp CharArrayHolder.h BaseHolderTree.cpp BaseHolderTree.h)
#add_executable(IUTestTask main.cpp IntHolder.cpp IntHolder.h BaseHolder.h )