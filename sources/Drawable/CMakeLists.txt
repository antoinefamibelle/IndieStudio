project("Drawable")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibDrawable)
    set(LIB_SRC_DIR src/)
    add_library(Drawable ${LIB_SRC_DIR}Drawable.cpp)
    target_include_directories(Drawable PUBLIC include)
    #target_link_libraries(Drawable PUBLIC Entity)
endfunction()

PrintLibCompil()
SetLibDrawable()