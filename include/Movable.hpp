/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Movable
*/

#pragma once

#include "Drawable.hpp"

namespace ECS {
    class Movable : public ECS::Drawable {
        public:
            Movable();
            ~Movable();

            void init() override;
            void update() override;

            void moveUp();
            void moveDown();
            void moveLeft();
            void moveRight();
        protected:

        private:
    };
}