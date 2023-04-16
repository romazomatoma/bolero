cmake_minimum_required(VERSION 3.11)

project(Bolero VERSION 0.0)
configure_file(BoleroConfig.h.in
               BoleroConfig.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(3rdparty)
add_subdirectory(src)

# なぜか初回は一度ビルドを成功させないと、ExternalProject_Addが呼ばれないので、ダミープロジェクトを用意した。
if(1)
    add_subdirectory(example)
else()
    add_executable(dummy_main example/dummy_main.cpp)
endif()
