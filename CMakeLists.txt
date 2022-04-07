cmake_minimum_required(VERSION 2.18)
project(BSKeyVS C)

set(CMAKE_C_STANDARD 99)

add_executable(BSKeyVS src/main.c src/main.h src/keyValStore.c src/keyValStore.h src/sub.c src/sub.h)
