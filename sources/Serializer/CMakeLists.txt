project("Serializer")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibSerealizer)
    set(LIB_SRC_DIR src/)
    add_library(Serializer ${LIB_SRC_DIR}Serializer.cpp)
    target_include_directories(Serializer PUBLIC include)
    target_link_libraries(Serializer PUBLIC Drawable PUBLIC FileManagement)
endfunction()

PrintLibCompil()
SetLibSerealizer()