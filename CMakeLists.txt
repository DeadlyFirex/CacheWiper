cmake_minimum_required(VERSION 3.0)
project(CacheWiper C)

set(CMAKE_C_STANDARD 11)

add_executable(CacheWiper main.c utils/color.c utils/color.h)
