include(ExternalProject)

set(MY_OPEN3D_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/open3d_install_dir CACHE PATH description)

ExternalProject_Add(
    open3d
    GIT_REPOSITORY https://github.com/isl-org/Open3D
    GIT_TAG "0a3f8c1864d5d37eb10f97876f0681ad6d3edaec"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${MY_OPEN3D_INSTALL_DIR}	
    -DBUILD_PYTHON_MODULE=OFF
    -DBUILD_ISPC_MODULE=OFF
)