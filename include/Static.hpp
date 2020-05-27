/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Static
*/

#pragma once
#include "Drawable.hpp"
#include "Object.hpp"

namespace ECS {
    class Static : ECS::Drawable{
        public:
            Static(){};
            ~Static(){};

            
        protected:
            using ECS::Object::getId;
            using ECS::Object::getPosX;
            using ECS::Object::getPosY;
            using ECS::Object::getType;
            using ECS::Object::isEmpty;
            using ECS::Object::setEmpty;
            using ECS::Object::setId;
            using ECS::Object::setPosY;
            using ECS::Object::setPoxX;
            using ECS::Object::setType;
        private:
    };
}
