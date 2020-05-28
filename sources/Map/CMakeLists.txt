project("Map")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibMap)
    set(LIB_SRC_DIR src/)
    add_library(Map ${LIB_SRC_DIR}Map.cpp)
    target_include_directories(Map PUBLIC include)
    target_link_libraries(Map PUBLIC Wall PUBLIC Floor)
endfunction()

PrintLibCompil()
SetLibMap()