project("FileManagement")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibFileManagement)
    set(LIB_SRC_DIR src/)
    add_library(FileManagement ${LIB_SRC_DIR}FileManagement.cpp)
    target_include_directories(FileManagement PUBLIC include)
    #target_link_libraries(FileManagement PUBLIC Entity)
endfunction()

PrintLibCompil()
SetLibFileManagement()