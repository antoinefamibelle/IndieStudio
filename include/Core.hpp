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

#include "Entity.hpp"

namespace Indie {
    class Core {
        public:
            Core(int);
            ~Core();

            void printMapInfo();
            void setMap(std::vector<std::pair<Indie::Entity *,int> > tmp) {this->_map = tmp; };
        protected:
            int _maxX; // Taille max de la map en largeur
            int _maxY; // Taille max de la map en longueur
            int _numberOfPlayer;
            int _score;
            std::vector<std::shared_ptr<Indie::Entity> > _players;
            std::vector<std::pair<Indie::Entity *,int> > _map;
        private:
    };
}