project("Floor")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibFloor)
    set(LIB_SRC_DIR src/)
    add_library(Floor ${LIB_SRC_DIR}Floor.cpp)
    target_include_directories(Floor PUBLIC include)
    target_link_libraries(Floor PUBLIC StaticEntity)
endfunction()

PrintLibCompil()
SetLibFloor()