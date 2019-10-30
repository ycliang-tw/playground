cmake_minimum_required(VERSION 2.8)
project(tutorial)
add_executable(demo1 main.c)
## math library -> libm.a or libm.so
## gcc -lm
target_link_libraries(demo1 libm.a)

