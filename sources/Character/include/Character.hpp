/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Character
*/

#pragma once

#include "Chrono.hpp"
#include "Controlable.hpp"


namespace ECS {
    class Character : public ECS::Controlable {
        public:
            Character(int, int, int);
            ~Character();

            bool isBombReady() { return this->_bombReady; };

        protected:
            bool _bombReady;
            Chrono _chrono;
            int _isAlive;
        private:
    };
}
