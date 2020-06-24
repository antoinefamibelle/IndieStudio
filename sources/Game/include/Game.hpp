/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Game
*/

#include "iostream"
#include <memory>
#include <vector>
#include "Character.hpp"
#include "MyIrrlicht.hpp"
#include "FileManagement.hpp"
#include "ManageMenu.hpp"
#include "TMap.hpp"
#include "Sound.hpp"
#include <algorithm>
#include "Chrono.hpp"

namespace Indie {
    class Game {
        public:
            Game();
            ~Game();

            int pause();
            void isTicking();
            void play(int, bool);
            void printMapInfo();
            void movePlayer(int index, ECS::Character *player);
            int isEnGame();
        protected:
        private:
            Sound *_sound;
            ManageMenu *_manageMenu;
            FileManagement *_File;
            int _numberOfPlayer;
            std::vector<std::string> _TextMap;
            TMap *_TMap;
            std::vector<ECS::Character *> _players;
            MyIrrlicht *_MyIrrlicht;
            // ECS::Character *_Joueur;
            Chrono _chrono;
            std::map<int, std::vector<std::pair<enum irr::EKEY_CODE, int>>> _map;

    };
}