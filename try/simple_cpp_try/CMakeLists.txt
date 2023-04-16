cmake_minimum_required(VERSION 3.11)

project(TRY)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp)

target_link_libraries(main optimized MyLibrary) # release
target_link_libraries(main debug MyLibraryD) # debug
