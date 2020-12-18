cmake_minimum_required(VERSION 2.8)
project(huffman-code)

set(CMAKE_C_STANDARD 99)

if (BUILD_TEST)
  add_definitions(-DHUFFANDPUFF_TEST)
  add_executable(test huffman.c vect.c)
else()
  add_library(compression STATIC huffman.c vect.c)
  add_executable(huffman huffman_main.c)
  target_link_libraries(huffman compression)
endif()