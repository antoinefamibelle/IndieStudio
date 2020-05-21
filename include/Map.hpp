/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Map
*/

#pragma once

#include "iostream"
#include "iomanip"
#include "fstream"
#include "vector"
#include "Entity.hpp"
#include "Wall.hpp"
#include "Floor.hpp"

namespace Indie {
    class Map {
        public:
            Map();
            ~Map();

            std::vector<std::pair<Indie::Entity *,int> > GenerateMap();
            void printMapInfo();
        protected:
            std::vector<std::string> openFile();
            
            std::ifstream _inFile;
            std::vector<std::pair<Indie::Entity *,int> > _map;
        private:
    };
}
