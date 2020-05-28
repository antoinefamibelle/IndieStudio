project("Movable")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibMovable)
    set(LIB_SRC_DIR src/)
    add_library(Movable ${LIB_SRC_DIR}Movable.cpp)
    target_include_directories(Movable PUBLIC include)
    target_link_libraries(Movable PUBLIC Drawable)
endfunction()

PrintLibCompil()
SetLibMovable()