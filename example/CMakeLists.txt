add_executable(main main.cpp)
target_include_directories(main PRIVATE "${PROJECT_BINARY_DIR}") # configにアクセスできるようにするため。

# glfw
target_include_directories(main PRIVATE ${GLFW_INSTALL_DIR}/include)
target_link_libraries(main ${GLFW_INSTALL_DIR}/lib/glfw3.lib)
