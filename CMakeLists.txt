cmake_minimum_required(VERSION 3.11)

project(Bolero VERSION 0.0)
configure_file(BoleroConfig.h.in
               BoleroConfig.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(3rdparty)
add_subdirectory(src)
add_subdirectory(example)