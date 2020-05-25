/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Wall
*/

#pragma once

#include "Static.hpp"
#include "Object.hpp"

namespace ECS {
    class Wall : public ECS::Static {
        public:
            Wall(int, int, int, ECS::ObjectType);
            ~Wall();

            bool isAlive() { return !this->_isAlive; };
        protected:
            bool _isAlive;
        private:
    };
}