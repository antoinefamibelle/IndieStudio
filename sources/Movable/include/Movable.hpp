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

        protected:
            using ECS::Drawable::setSprite;
            using ECS::Object::getId;
            using ECS::Object::getPosX;
            using ECS::Object::getPosY;
            using ECS::Object::getType;
            using ECS::Object::setId;
            using ECS::Object::setPosY;
            using ECS::Object::setPosX;

            // Utile ???
            using ECS::Object::setType;
            using ECS::Object::isEmpty;
            using ECS::Object::setEmpty;
        private:
    };
}