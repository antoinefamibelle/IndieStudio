project("Bomb")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibBomb)
    set(LIB_SRC_DIR src/)
    add_library(Bomb ${LIB_SRC_DIR}Bomb.cpp)
    target_include_directories(Bomb PUBLIC include)
    target_link_libraries(Bomb PUBLIC Chrono PUBLIC StaticEntity)
endfunction()

PrintLibCompil()
SetLibBomb()