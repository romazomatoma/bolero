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

if (WIN32)
    set(my_list ".dll" "d.dll")
    set(osg_dll_path ${MY_OSG_INSTALL_DIR}/bin/)
    foreach(AFT IN LISTS my_list)
        add_custom_command(
            TARGET main POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osg${AFT} ${CMAKE_CURRENT_BINARY_DIR}
            COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osgViewer${AFT} ${CMAKE_CURRENT_BINARY_DIR}
            COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osgGA${AFT} ${CMAKE_CURRENT_BINARY_DIR}
            COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osgText${AFT} ${CMAKE_CURRENT_BINARY_DIR}
            COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}ot21-OpenThreads${AFT} ${CMAKE_CURRENT_BINARY_DIR}
            COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osgDB${AFT} ${CMAKE_CURRENT_BINARY_DIR}
            COMMAND ${CMAKE_COMMAND} -E copy ${osg_dll_path}osg161-osgUtil${AFT} ${CMAKE_CURRENT_BINARY_DIR})
    endforeach()
elseif(APPLE)
    set(osg_lib_list_apple
        libOpenThreads.3.3.1.dylib
        libosgShadow.3.6.5.dylib
        libosg.3.6.5.dylib
        libosgSim.3.6.5.dylib
        libosgAnimation.3.6.5.dylib
        libosgTerrain.3.6.5.dylib
        libosgDB.3.6.5.dylib
        libosgText.3.6.5.dylib
        libosgFX.3.6.5.dylib
        libosgUI.3.6.5.dylib
        libosgGA.3.6.5.dylib
        libosgUtil.3.6.5.dylib
        libosgManipulator.3.6.5.dylib
        libosgViewer.3.6.5.dylib
        libosgParticle.3.6.5.dylib
        libosgVolume.3.6.5.dylib
        libosgPresentation.3.6.5.dylib
        libosgWidget.3.6.5.dylib
        )
    foreach(libName IN LISTS osg_lib_list_apple)
        target_link_libraries(main ${MY_OSG_INSTALL_DIR}/lib/${libName})
    endforeach()
elseif(UNIX)
endif()

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
        foreach(libName IN LISTS osg_lib_list)
            target_link_libraries(main debug ${MY_OSG_INSTALL_DIR}/lib/${libName}d.lib)
            target_link_libraries(main optimized ${MY_OSG_INSTALL_DIR}/lib/${libName}.lib)
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
