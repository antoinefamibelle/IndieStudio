/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Core
*/

#pragma once

#include "vector"
#include "memory"
#include "iostream"
#include "string"
#include "map"

#include "StaticEntity.hpp"
#include "MovableEntity.hpp"
#include "Object.hpp"

namespace Indie {
    class Core {
        public:
            Core(int);
            ~Core();

            void run();
            void printMapInfo();
            void setMap(std::vector<std::pair<std::shared_ptr<ECS::StaticEntity>,int>> tmp) {this->_map = tmp; };
        protected:
            int _maxX; // Taille max de la map en largeur
            int _maxY; // Taille max de la map en longueur
            int _numberOfPlayer;
            int _score;
            std::vector<std::shared_ptr<ECS::MovableEntity>> _players;
            std::vector<std::pair<std::shared_ptr<ECS::StaticEntity>,int>> _map;
        private:
    };
}