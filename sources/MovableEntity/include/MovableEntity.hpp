/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** MovableEntity
*/

#pragma once

#include "Movable.hpp"

namespace ECS {
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    class MovableEntity : public ECS::Movable {
        public:
            MovableEntity();
            ~MovableEntity();

            bool canMove(enum Direction direction, std::vector<std::string> map);
            bool move(enum Direction direction, std::vector<std::string> map);
        protected:
        private:
    };
}