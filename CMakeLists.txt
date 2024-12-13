# Generated from QtWs2022.pro.

cmake_minimum_required(VERSION 3.16)
project(QtWs2022 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Quick QuickControls2)

set(PROJECT_SOURCES
    ResourceService.cpp ResourceService.h
    Scene.cpp Scene.h
    SceneProvider.cpp SceneProvider.h
    SceneProviderRenderer.cpp SceneProviderRenderer.h
    SceneRenderer.cpp SceneRenderer.h
    ServiceManager.cpp ServiceManager.h
    main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt6 REQUIRED COMPONENTS Core5Compat)
    qt_add_executable(QtWs2022 WIN32 MACOSX_BUNDLE
        ${PROJECT_SOURCES}
    )

    set(qml_resource_files
        "Main6.qml"
        "SeparateWindow.qml"
    )

    set(resource_files
        "cube.fsh"
        "cube.vsh"
        "quad.fsh"
        "quad.vsh"
        "watermelon.jpg"
    )

    qt6_add_resources(QtWs2022 "resources"
        PREFIX
            "/"
        FILES
            ${resource_files}
    )

    qt_add_qml_module(QtWs2022
        URI com.example.QtWs2022
        VERSION 1.0
        QML_FILES "Main6.qml" "SeparateWindow.qml"
    )
else()
    # Append the qt resources to the PROJECT_SOURCES for Qt5 builds.
    list(APPEND PROJECT_SOURCES "qml.qrc")
    add_executable(QtWs2022
      ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(QtWs2022 PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Quick
    Qt::QuickControls2
)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    target_link_libraries(QtWs2022 PRIVATE
        Qt6::Core5Compat
    )
endif()

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QtWs2022)
endif()
set_target_properties(QtWs2022 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Resources:
install(TARGETS QtWs2022
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
