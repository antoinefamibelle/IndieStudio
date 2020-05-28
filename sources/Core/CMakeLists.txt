project("Core")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibCore)
    set(LIB_SRC_DIR src/)
    add_library(Core ${LIB_SRC_DIR}Core.cpp)
    target_include_directories(Core PUBLIC include)
    target_link_libraries(Core PUBLIC Character PUBLIC Wall PUBLIC StaticEntity PUBLIC Floor)
endfunction()

PrintLibCompil()
SetLibCore()