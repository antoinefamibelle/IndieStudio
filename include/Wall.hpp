/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Wall
*/

#pragma once

#include "StaticEntity.hpp"
#include "Object.hpp"

namespace ECS {
    class Wall : public ECS::StaticEntity {
        public:
            Wall(int, int, int, ECS::ObjectType);
            ~Wall();

            bool isAlive() { return !this->_isAlive; };
        protected:
            bool _isAlive;
        private:
    };
}