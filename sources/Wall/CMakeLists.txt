project("Wall")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibWall)
    set(LIB_SRC_DIR src/)
    add_library(Wall ${LIB_SRC_DIR}Wall.cpp)
    target_include_directories(Wall PUBLIC include)
    target_link_libraries(Wall PUBLIC StaticEntity)
endfunction()

PrintLibCompil()
SetLibWall()