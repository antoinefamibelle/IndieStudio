/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Character
*/

#pragma once

#include "Entity.hpp"
#include "Chrono.hpp"

namespace Indie {
    class Character : public Indie::Entity {
        public:
            Character(int, int, int);
            ~Character();

            bool isBombReady() { return this->_bombReady; };

        protected:
            bool _bombReady;
            Chrono _chrono;

        private:
    };
}