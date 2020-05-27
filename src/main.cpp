/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** main
*/

#include "iostream"
#include "Wall.hpp"
#include "Floor.hpp"
#include "Core.hpp"
#include "Character.hpp"
#include "Map.hpp"

int main()
{
    Indie::Core *core = new Indie::Core(4);

    try {
        core->run();
    } catch(char *message) {
        std::cout << message << std::endl;
    }
    return 0;
}