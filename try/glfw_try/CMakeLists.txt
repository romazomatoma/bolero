cmake_minimum_required(VERSION 3.11)

project(Bolero)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(ExternalProject)

set(MY_GLFW_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/my_install_dir CACHE PATH description)

set(LIB_GLFW ${MY_GLFW_INSTALL_DIR}/lib/libglfw3.a)

ExternalProject_Add(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG 3.3.8
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${MY_GLFW_INSTALL_DIR}
	-DGLFW_BUILD_EXAMPLES=Off
	-DGLFW_BUILD_TESTS=Off
	-DGLFW_BUILD_DOCS=Off

        # https://stackoverflow.com/questions/74096285/cmake-build-dependency-downloaded-with-externalproject-add-before-hand
        # BUILD_BYPRODUCTSをやらないと、生成物が必要になる前に、リポジトリのビルドを行ってくれない。
    BUILD_BYPRODUCTS ${LIB_GLFW}
)

add_executable(main main.cpp)

add_dependencies(main glfw)

target_include_directories(main PRIVATE ${MY_GLFW_INSTALL_DIR}/include)

target_link_libraries(main ${LIB_GLFW})
target_link_libraries(main OpenGL32.Lib)
