project("StaticEntity")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibStaticEntity)
    set(LIB_SRC_DIR src/)
    add_library(StaticEntity ${LIB_SRC_DIR}StaticEntity.cpp)
    target_include_directories(StaticEntity PUBLIC include)
    target_link_libraries(StaticEntity PUBLIC Drawable)
endfunction()

PrintLibCompil()
SetLibStaticEntity()