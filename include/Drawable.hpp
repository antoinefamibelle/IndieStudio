/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Drawable
*/

#pragma once

#include "Object.hpp"

namespace ECS {
    class Drawable : public ECS::Object{
        public:
            Drawable();
            ~Drawable();

            void init() override;
            void update() override;
            void draw() {};
        protected:
            // voir ce dont on a besoin pour draw un object
        private:
    };
}
