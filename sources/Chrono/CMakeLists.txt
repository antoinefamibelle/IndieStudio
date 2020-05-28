project("Chrono")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibChrono)
    set(LIB_SRC_DIR src/)
    add_library(Chrono ${LIB_SRC_DIR}Chrono.cpp)
    target_include_directories(Chrono PUBLIC include)
    #target_link_libraries(Chrono PUBLIC Entity)
endfunction()

PrintLibCompil()
SetLibChrono()