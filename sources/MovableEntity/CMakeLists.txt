project("MovableEntity")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibMovableEntity)
    set(LIB_SRC_DIR src/)
    add_library(MovableEntity ${LIB_SRC_DIR}MovableEntity.cpp)
    target_include_directories(MovableEntity PUBLIC include)
    #target_link_libraries(MovableEntity PUBLIC Entity)
endfunction()

PrintLibCompil()
SetLibMovableEntity()