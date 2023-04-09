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

# glew
target_include_directories(main PRIVATE ${GLEW_INSTALL_DIR}/glew-src/include)
target_compile_definitions(main PRIVATE GLEW_STATIC)

IF (WIN32)

target_link_libraries(main ${GLFW_INSTALL_DIR}/lib/glfw3.lib)
target_link_libraries(main ${GLEW_INSTALL_DIR}/Release/glew.lib)
target_link_libraries(main OpenGL32.Lib)
ELSEIF (UNIX)
target_link_libraries(main ${GLFW_INSTALL_DIR}/lib/libglfw3.a)
target_link_libraries(main ${GLEW_INSTALL_DIR}/libglew.a)
find_package(OpenGL REQUIRED)
target_link_libraries(main OpenGL::GL OpenGL::GLU)
IF (APPLE)
find_library(COCOA_LIBRARY Cocoa)
find_library(IOKIT_LIBRARY IOKit)
target_link_libraries(main ${COCOA_LIBRARY} ${IOKIT_LIBRARY})
ELSE()
target_link_libraries(main X11 Xxf86vm Xrandr pthread Xi dl)
ENDIF()

ENDIF()

# imgui
target_include_directories(main PRIVATE ${IMGUI_SOURCE_DIR})

# glm
target_include_directories(main PRIVATE ${GLM_SOURCE_DIR})