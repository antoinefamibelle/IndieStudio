project("Character")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibCharacter)
    set(LIB_SRC_DIR src/)
    add_library(Character ${LIB_SRC_DIR}Character.cpp)
    target_include_directories(Character PUBLIC include)
    target_link_libraries(Character PUBLIC Chrono PUBLIC Movable)
endfunction()

PrintLibCompil()
SetLibCharacter()