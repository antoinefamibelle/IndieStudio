project("JsonParser")

function(PrintLibCompil)
    message("${Green}++ Lib du projet: \"${PROJECT_NAME}\" générée avec succès ${ColourReset}")
endfunction()

function(SetLibJsonParser)
    set(LIB_SRC_DIR src/)
    add_library(JsonParser ${LIB_SRC_DIR}JsonParser.cpp)
    target_include_directories(JsonParser PUBLIC include)
    target_link_libraries(JsonParser PUBLIC Serializer PUBLIC Deserializer)
endfunction()

PrintLibCompil()
SetLibJsonParser()