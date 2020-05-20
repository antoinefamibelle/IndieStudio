/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Wall
*/

#pragma once

#include "Entity.hpp"

namespace Indie {
    class Wall : public Indie::Entity {
        public:
            Wall(int, int, int, Indie::EntityType);
            ~Wall();

            bool isFree() { return !this->_bomb; } ;
        protected:
            bool _bomb;
        private:
    };
}