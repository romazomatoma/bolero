include(ExternalProject)

set(GLFW_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/glfw_install_dir CACHE PATH description)
set(GLFW_LIB ${GLFW_INSTALL_DIR}/lib/libglfw3.a CACHE PATH description)

ExternalProject_Add(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GLFW_INSTALL_DIR}
    -DGLFW_BUILD_EXAMPLES=Off
    -DGLFW_BUILD_TESTS=Off
    -DGLFW_BUILD_DOCS=Off
    BUILD_BYPRODUCTS ${GLFW_LIB}
)
