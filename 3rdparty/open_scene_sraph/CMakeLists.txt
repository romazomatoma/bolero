include(ExternalProject)

set(MY_OSG_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/install CACHE PATH description)

ExternalProject_Add(
    osg
    GIT_REPOSITORY https://github.com/openscenegraph/OpenSceneGraph
    GIT_TAG "OpenSceneGraph-3.6.5"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${MY_OSG_INSTALL_DIR}
if(WIN32)
    -DBUILD_OSG_PLUGINS_BY_DEFAULT:BOOL=0
    -DBUILD_OSG_EXAMPLES:BOOL=1
    -DBUILD_OSG_APPLICATIONS:BOOL=0
endif()    
    #-DCMAKE_CONFIGURATION_TYPES:STRING=Debug;Release;
    -DBUILD_OSG_DEPRECATED_SERIALIZERS:BOOL=0
)