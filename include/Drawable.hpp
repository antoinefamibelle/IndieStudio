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

            void draw() {};
            
        protected:
            void setSprite();

            std::string _spriteFile;
            
            // voir ce dont on a besoin pour draw un object
        private:
    };
}
