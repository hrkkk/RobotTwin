﻿cmake_minimum_required(VERSION 3.5)

project(RobotTwin VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DMODEL_DIR="${PROJECT_SOURCE_DIR}/model/")
add_definitions(-DSHADER_DIR="${PROJECT_SOURCE_DIR}/shader/")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets SerialPort)

include_directories(./)
include_directories(./3rd-party/GLFW/include/)
include_directories(./3rd-party/GLM/)

link_directories(./3rd-party/GLFW/)

# Windows系统
if (WIN32)
    include_directories(./3rd-party/GLEW/windows/glew-2.1.0/include)
    link_directories(./3rd-party/GLEW/windows/glew-2.1.0/lib/Release/x64)
    # MinGW编译器
    if (CMAKE_COMPILER_IS_GNUCXX)
        include_directories(./3rd-party/assimp/mingw/include/)
        link_directories(./3rd-party/assimp/mingw/bin/)
    # MSVC编译器
    else()
        include_directories(./3rd-party/assimp/msvc/include/)
        link_directories(./3rd-party/assimp/msvc/lib/)
    endif()
# MacOS系统
elseif (APPLE)
    find_package(ASSIMP REQUIRED)
    include_directories(./3rd-party/GLEW/macosx/glew/2.2.0_1/include)
    link_directories(./3rd-party/GLEW/macosx/glew/2.2.0_1/lib)
endif()

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        shader.h camera.h model.h stb_image.h stb_image.cpp mesh.h
        Arm_IK.cpp Arm_IK.h
        serialport.cpp serialport.h
        CustomOpenGLWidget.h CustomOpenGLWidget.cpp
        res.qrc
        Render.cpp
        Render.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(RobotTwin
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(RobotTwin SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(RobotTwin
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Windows系统
if (WIN32)
    # MinGW编译器
    if (CMAKE_COMPILER_IS_GNUCXX)
        target_link_libraries(RobotTwin PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::SerialPort Qt${QT_VERSION_MAJOR}::OpenGLWidgets opengl32.lib libassimp-5.dll glew32.lib)
    # MSVC编译器
    else()
        target_link_libraries(RobotTwin PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::SerialPort Qt${QT_VERSION_MAJOR}::OpenGLWidgets opengl32.lib assimp-vc143-mt.lib glew32.lib)
    endif()
# MacOS系统
elseif(APPLE)
    target_link_directories(RobotTwin PRIVATE ${ASSIMP_INCLUDE_DIRS})
    target_link_libraries(RobotTwin PRIVATE Qt6::Widgets Qt6::SerialPort Qt6::OpenGLWidgets ${ASSIMP_LIBRARIES} libGLEW.a "-framework OpenGL")
endif()


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.RobotTwin)
endif()
set_target_properties(RobotTwin PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS RobotTwin
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(RobotTwin)
endif()
