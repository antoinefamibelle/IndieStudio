/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** main
*/

#include "irrlicht.h"
#include "MyIrrlicht.hpp"
#include <irrlicht.h>
#include "driverChoice.h"
#include "Game.hpp"
#include "ManageMenu.hpp"
#include "memory"

#include "AI.hpp"

int main(void)
{
    Indie::Game game = Indie::Game();
    ManageMenu *Menu = new ManageMenu();
    int choice = 0;

    try {
        choice = Menu->head();
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5) {
            Menu->getSound()->menuMusicStop();
            game.play(choice == 5 ? 1 : choice, choice == 5 ? true : false);
        }
        else if (choice == -1)
            return 0;
        else {
            throw "Undefined number of player";
        }
    } catch(std::string message) {
        std::cout << "[ERROR] : " << message << std::endl;
    }
    return 0;
}