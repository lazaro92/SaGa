cmake_minimum_required(VERSION 3.28)
project(example
  LANGUAGES CXX
  VERSION 1.0
)

add_subdirectory(dependencies)


add_executable(example_exe main.cpp)
target_link_libraries(example_exe PRIVATE sfml-graphics)

