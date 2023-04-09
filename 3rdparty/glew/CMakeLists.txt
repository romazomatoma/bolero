# https://qiita.com/ousttrue/items/4fa7a786a6c51e9f11f0

include(FetchContent)
FetchContent_Populate(
  glew
  URL https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0.tgz/download
)
add_library(glew
  ${glew_SOURCE_DIR}/src/glew.c
  ${glew_SOURCE_DIR}/src/glewinfo.c
  ${glew_SOURCE_DIR}/src/visualinfo.c
)
target_include_directories(glew PRIVATE ${glew_SOURCE_DIR}/include)
target_compile_definitions(glew PRIVATE GLEW_STATIC)

set(GLEW_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR} CACHE PATH description)