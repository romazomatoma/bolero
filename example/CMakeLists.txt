add_executable(main main.cpp
    ${IMGUI_SOURCE_DIR}/imgui.cpp
    ${IMGUI_SOURCE_DIR}/imgui_demo.cpp
    ${IMGUI_SOURCE_DIR}/imgui_draw.cpp
    ${IMGUI_SOURCE_DIR}/imgui_tables.cpp
    ${IMGUI_SOURCE_DIR}/imgui_widgets.cpp
    ${IMGUI_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp


    section_manager.cpp

    main_glfw.cpp

    example_section.cpp

)
target_include_directories(main PRIVATE "${PROJECT_BINARY_DIR}") # configにアクセスできるようにするため。

# glfw
target_include_directories(main PRIVATE ${GLFW_INSTALL_DIR}/include)

# glew
target_include_directories(main PRIVATE ${GLEW_INSTALL_DIR}/glew-src/include)
target_compile_definitions(main PRIVATE GLEW_STATIC)

# osg
target_include_directories(main PRIVATE ${MY_OSG_INSTALL_DIR}/include)

#osg161-osg;
#osg161-osgAnimation;
#osg161-osgAnimationd;
#osg161-osgd;
#osg161-osgDB;
#osg161-osgDBd;
#osg161-osgFX;
#osg161-osgFXd;
#osg161-osgGA;
#osg161-osgGAd;
#osg161-osgManipulator;
#osg161-osgManipulatord;
#osg161-osgParticle;
#osg161-osgParticled;
#osg161-osgPresentation;
#osg161-osgPresentationd;
#osg161-osgShadow;
#osg161-osgShadowd;
#osg161-osgSim;
#osg161-osgSimd;
#osg161-osgTerrain;
#osg161-osgTerraind;
#osg161-osgText;
#osg161-osgTextd;
#osg161-osgUI;
#osg161-osgUId;
#osg161-osgUtil;
#osg161-osgUtild;
#osg161-osgViewer;
#osg161-osgViewerd;
#osg161-osgVolume;
#osg161-osgVolumed;
#osg161-osgWidget;
#osg161-osgWidgetd;
#ot21-OpenThreads;
#ot21-OpenThreadsd;"

set(my_list ".dll" "d.dll")
set(osg_dll_path ${MY_OSG_INSTALL_DIR}/bin/)
foreach(AFT IN LISTS my_list)
    add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osg${AFT} ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osgViewer${AFT} ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osgGA${AFT} ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osgText${AFT} ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}ot21-OpenThreads${AFT} ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osgDB${AFT} ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osgUtil${AFT} ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

# lib
set(osg_lib_list
    "OpenThreads"
    "osg"
    "osgAnimation"
    "osgDB"
    "osgFX"
    "osgGA"
    "osgManipulator"
    "osgParticle"
    "osgPresentation"
    "osgShadow"
    "osgSim"
    "osgTerrain"
    "osgText"
    "osgUI"
    "osgUtil"
    "osgViewer"
    "osgVolume"
    "osgWidget"
)

if (WIN32)
    if(MSVC)
        target_link_libraries(main ${GLFW_INSTALL_DIR}/lib/glfw3.lib)
        foreach(n IN LISTS osg_lib_list)
            target_link_libraries(main debug ${MY_OSG_INSTALL_DIR}/lib/${n}d.lib)
            target_link_libraries(main optimized ${MY_OSG_INSTALL_DIR}/lib/${n}.lib)
        endforeach()
    else()
        target_link_libraries(main ${GLFW_LIB})
    endif()

    target_link_libraries(main ${GLEW_INSTALL_DIR}/Release/glew.lib)
    target_link_libraries(main OpenGL32.Lib)
elseif (UNIX)
    target_link_libraries(main ${GLFW_LIB})
    target_link_libraries(main ${GLEW_INSTALL_DIR}/libglew.a)
    find_package(OpenGL REQUIRED)
    target_link_libraries(main OpenGL::GL OpenGL::GLU)
    if (APPLE)
        find_library(COCOA_LIBRARY Cocoa)
        find_library(IOKIT_LIBRARY IOKit)
        target_link_libraries(main ${COCOA_LIBRARY} ${IOKIT_LIBRARY})
    else()
        target_link_libraries(main X11 Xxf86vm Xrandr pthread Xi dl)
    endif()

endif()

# imgui
target_include_directories(main PRIVATE ${IMGUI_SOURCE_DIR})

# glm
target_include_directories(main PRIVATE ${GLM_SOURCE_DIR})
