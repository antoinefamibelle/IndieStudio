project("MapGenerator")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibMapGenerator)
    set(LIB_SRC_DIR src/)
    add_library(MapGenerator ${LIB_SRC_DIR}MapGenerator.cpp)
    target_include_directories(MapGenerator PUBLIC include)
    #target_link_libraries(MapGenerator PUBLIC Entity)
endfunction()

PrintLibCompil()
SetLibMapGenerator()