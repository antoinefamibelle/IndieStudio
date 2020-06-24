cmake_minimum_required(VERSION 3.0)

project(indie_studio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g3 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio")

include_directories(./libraries/irrklang/includes
		    ./libraries/irrlicht/includes
		    ./sources/AI/include
            ./sources/Bomb/include
            ./sources/Game/include
            ./sources/Character/include
            ./sources/Chrono/include
            ./sources/Core/include
            ./sources/Deserializer/include
            ./sources/Drawable/include
            ./sources/Explosion/include
            ./sources/FileManagement/include
            ./sources/Floor/include
            ./sources/ManageMenu/include
            ./sources/JsonParser/include
            ./sources/Map/include
            ./sources/MapGenerator/include
            ./sources/Menu/Button/include
            ./sources/Menu/Menu/include
            ./sources/Movable/include
            ./sources/MovableEntity/include
            ./sources/MyIrrlicht/include
            ./sources/Serializer/include
            ./sources/StaticEntity/include
            ./sources/Sound/include
            ./sources/Wall/include
            ./sources/TMap/include
		    )

if(UNIX)

set(CMAKE_SKIP_BUILD_RPATH_FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "$ENV{HOME}/indie_studio")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/release")

set(IRRKLANG_LIBRARY libIrrklang.so)

link_directories(./libraries/irrklang/linux)

set(IRRLICHT_LIBRARY
    -L./libraries/irrlicht/linux
    -lIrrlicht
    -lGL
    -lGLU
    -lXext
    -lX11
    -lXxf86vm
    )

add_executable(indie_studio

            sources/AI/src/AI.cpp
            sources/Bomb/src/Bomb.cpp
            sources/Game/src/Game.cpp
            sources/Character/src/Character.cpp
            sources/Chrono/src/Chrono.cpp
            sources/Core/src/Core.cpp
            sources/Deserializer/src/Deserializer.cpp
            sources/Drawable/src/Drawable.cpp
            sources/Explosion/src/Explosion.cpp
            sources/FileManagement/src/FileManagement.cpp
            sources/Floor/src/Floor.cpp
            sources/ManageMenu/src/ManageMenu.cpp
            sources/JsonParser/src/JsonParser.cpp
            sources/Map/src/Map.cpp
            sources/MapGenerator/src/MapGenerator.cpp
            sources/Menu/Button/source/Button.cpp
            sources/Menu/Menu/source/Menu.cpp
            sources/Movable/src/Movable.cpp
            sources/MovableEntity/src/MovableEntity.cpp
            sources/MyIrrlicht/src/MyIrrlicht.cpp
            sources/Serializer/src/Serializer.cpp
            sources/StaticEntity/src/StaticEntity.cpp
            sources/Sound/src/Sound.cpp
            sources/Wall/src/Wall.cpp
            sources/TMap/src/TMap.cpp
            sources/main.cpp

	       )

target_link_libraries(indie_studio
		      ${IRRKLANG_LIBRARY}
		      ${IRRLICHT_LIBRARY}
		      )

install(TARGETS indie_studio DESTINATION "$ENV{HOME}/indie_studio")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/release/ikpFlac.so"
        DESTINATION "$ENV{HOME}/indie_studio")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/release/ikpMP3.so"
        DESTINATION "$ENV{HOME}/indie_studio")
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/release/media"
        DESTINATION "$ENV{HOME}/indie_studio")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/libraries/irrklang/linux/libIrrklang.so" DESTINATION "$ENV{HOME}/indie_studio")

elseif(WIN32)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/release")

add_library(Irrklang STATIC IMPORTED)
add_library(Irrlicht STATIC IMPORTED)

set_property(TARGET Irrklang PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/libraries/irrklang/windows/libIrrklang.a)
set_property(TARGET Irrlicht PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/libraries/irrlicht/windows/libIrrlicht.a)

add_executable(indie_studio

            sources/AI/src/AI.cpp
            sources/Bomb/src/Bomb.cpp
            sources/Game/src/Game.cpp
            sources/Character/src/Character.cpp
            sources/Chrono/src/Chrono.cpp
            sources/Core/src/Core.cpp
            sources/Deserializer/src/Deserializer.cpp
            sources/Drawable/src/Drawable.cpp
            sources/Explosion/src/Explosion.cpp
            sources/FileManagement/src/FileManagement.cpp
            sources/Floor/src/Floor.cpp
            sources/ManageMenu/src/ManageMenu.cpp
            sources/JsonParser/src/JsonParser.cpp
            sources/Map/src/Map.cpp
            sources/MapGenerator/src/MapGenerator.cpp
            sources/Menu/Button/source/Button.cpp
            sources/Menu/Menu/source/Menu.cpp
            sources/Movable/src/Movable.cpp
            sources/MovableEntity/src/MovableEntity.cpp
            sources/MyIrrlicht/src/MyIrrlicht.cpp
            sources/Serializer/src/Serializer.cpp
            sources/StaticEntity/src/StaticEntity.cpp
            sources/Sound/src/Sound.cpp
            sources/Wall/src/Wall.cpp
            sources/TMap/src/TMap.cpp

	       )

target_link_libraries(indie_studio
		      Irrklang
		      Irrlicht
		      )

endif(UNIX)