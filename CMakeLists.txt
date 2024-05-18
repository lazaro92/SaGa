cmake_minimum_required(VERSION 3.28)
project(example
  LANGUAGES CXX
  VERSION 1.0
)

add_subdirectory(dependencies)
add_subdirectory(src)
