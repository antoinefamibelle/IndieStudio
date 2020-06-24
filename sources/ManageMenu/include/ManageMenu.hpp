/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** ManageMenu
*/

#ifndef MANAGEMENU_HPP_
#define MANAGEMENU_HPP_

#include "Menu.hpp"
#include "TMap.hpp"
#include "MyIrrlicht.hpp"
#include "Sound.hpp"

class ManageMenu {
    public:
        ManageMenu();
        ~ManageMenu();

        std::string manageMenu(Menu *menu);
        Menu *getMenu(std::string choice) { return choice == "startMenu" ? this->startMenu : this->multiplayerMenu; };
        void displayMenu(Menu *menu);
        std::string MenuProcess();
        int head();
        std::vector<std::pair<Button, bool>> createVector(std::vector<std::string> name, int x, int y, int sizeX, int sizeY, std::vector<std::pair<ITexture *, ITexture *>> buttons, bool isSpecial);
        void displaySpecialMenu();
        std::string EndMenuProcess(int index);
        void DisplayMap();
        Sound *getSound() { return this->_sound; };
        std::string PauseMenuProcess();

    protected:
    private:
        std::vector<std::pair<Button, bool>> createVector(std::vector<std::string> name, int x, int y, int sizeX, int sizeY, ITexture *texture, ITexture *pressed);
        Menu *startMenu;
        Menu *multiplayerMenu;
        Menu *soloMenu;
        Menu *endMenu;
        Menu *pauseMenu;
        Sound *_sound;
        MyIrrlicht *_irrlicht;
        // A CHANGER WLH
        std::vector<std::string> specialMenu = {"./Assets/images/blue_sliderLeft.png", "./Assets/images/blue_sliderRight.png", "./Assets/images/blue_tick.png", "./Assets/images/blue_cross.png"};

};

#endif /* !MANAGEMENU_HPP_ */
