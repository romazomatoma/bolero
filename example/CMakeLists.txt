add_executable(main main.cpp
${IMGUI_SOURCE_DIR}/imgui.cpp
${IMGUI_SOURCE_DIR}/imgui_demo.cpp
${IMGUI_SOURCE_DIR}/imgui_draw.cpp
${IMGUI_SOURCE_DIR}/imgui_tables.cpp
${IMGUI_SOURCE_DIR}/imgui_widgets.cpp
${IMGUI_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
${IMGUI_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)
target_include_directories(main PRIVATE "${PROJECT_BINARY_DIR}") # configにアクセスできるようにするため。

# glfw
target_include_directories(main PRIVATE ${GLFW_INSTALL_DIR}/include)
target_link_libraries(main ${GLFW_INSTALL_DIR}/lib/glfw3.lib)

# imgui
target_include_directories(main PRIVATE ${IMGUI_SOURCE_DIR})
