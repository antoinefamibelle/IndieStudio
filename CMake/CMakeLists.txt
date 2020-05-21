cmake_minimum_required(VERSION 3.0)
PROJECT(IndieStudio)
SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}" "${CMAKE_MODULE_PATH}")
set(LIBRARY_SEARCH_PATH
  /usr/local
  /opt/local
  /usr
  /opt
)


set(HEADER_SEARCH_PATH
  /usr/local
  /opt/local
  /usr
  /opt
)

FIND_PACKAGE(Irrlicht)
find_package(OpenGL)
find_package(X11)


find_path(GLFW_INCLUDE_DIR GLFW/glfw3.h ${HEADER_SEARCH_PATH})


find_library(GLFW_LIBRARIES glfw3 ${LIBRARY_SEARCH_PATH})


set( ADDITIONAL_LIBS 
     -lGLU 
     -pthread
     -lrt
     -lXrandr
     -lXxf86vm
     -lIrrlicht
     -lGL
     -lXext
     -lX11
     -lsfml-system
     -lsfml-audio
)


set(INCLUDE_PATH
  ${OPENGL_INCLUDE_DIR}
)


set(LIBRARIES
  ${OPENGL_LIBRARIES}
  ${X11_LIBRARIES}
  ${ADDITIONAL_LIBS}  
)


find_path(GLEW_INCLUDE_DIR GL/glew.h
    ${HEADER_SEARCH_PATH}
)


set(INCLUDE_PATH ${INCUDE_PATH}
    ${GLEW_INCLUDE_DIR} 
    )
set(EXECUTABLE_OUTPUT_PATH ../)

INCLUDE_DIRECTORIES(
  ../include
  "./include/irr/irrlicht"
  ${SFML_INCLUDE_DIR}
  )
SET(IndieStudio_SOURCE_FILES
                ../src/main.cpp
                ../src/Chrono.cpp
                ../src/Core.cpp
                ../src/Map.cpp
                ../src/Entity/Character.cpp
                ../src/Entity/Floor.cpp
                ../src/Entity/Wall.cpp
                ../src/Entity/Entity.cpp
  )

ADD_EXECUTABLE(IndieStudio WIN32  ${IndieStudio_SOURCE_FILES})

TARGET_LINK_LIBRARIES(IndieStudio
 ${IRRLICHT_LIBRARIES}
 ${LIBRARIES}
 )
