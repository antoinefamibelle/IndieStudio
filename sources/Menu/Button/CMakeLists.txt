project("Button")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibButton)
    set(LIB_SRC_DIR src/)
    add_library(Button ${LIB_SRC_DIR}Button.cpp)
    target_include_directories(Button PUBLIC include)
    target_link_libraries(Button PUBLIC StaticEntity)
endfunction()

PrintLibCompil()
SetLibButton()