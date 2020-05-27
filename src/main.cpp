/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** main
*/

#include "JsonParser.hpp"
#include "Object.hpp"

// #include "iostream"
// // #include "Wall.hpp"
// // #include "Floor.hpp"
// // #include "Core.hpp"
// // #include "Character.hpp"
// // #include "Map.hpp"

// int main()
// {
//     Indie::Core *core = new Indie::Core(4);
//     Indie::Map *map = new Indie::Map();

//     try {
//         core->setMap(map->GenerateMap());
//         core->printMapInfo();
//     } catch(char *message) {
//         std::cout << message << std::endl;
//     }
//     return 0;
// }

int main()
{
    ECS::Object *_object = new ECS::Object();
    std::vector<ECS::Object *> object;
    JsonParser *_parser = new JsonParser();

    object.push_back(_object);
    _parser->serializer->serialize(object);
    return 0;
}