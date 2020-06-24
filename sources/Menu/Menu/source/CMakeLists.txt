project("Menu")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibMenu)
    set(LIB_SRC_DIR src/)
    add_library(Menu ${LIB_SRC_DIR}Menu.cpp)
    target_include_directories(Menu PUBLIC include)
    target_link_libraries(Menu PUBLIC Button)
endfunction()

PrintLibCompil()
SetLibMenu()