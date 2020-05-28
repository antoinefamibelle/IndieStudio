project("Deserializer")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibDeserealizer)
    set(LIB_SRC_DIR src/)
    add_library(Deserializer ${LIB_SRC_DIR}Deserializer.cpp)
    target_include_directories(Deserializer PUBLIC include)
    target_link_libraries(Deserializer PUBLIC FileManagement PUBLIC Drawable)
endfunction()

PrintLibCompil()
SetLibDeserealizer()