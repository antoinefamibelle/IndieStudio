/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Controlable
*/

#pragma once

#include "MovableEntity.hpp"

namespace ECS {
    enum InputType {
        LeftInput,
        RightInput,
        UpInput,
        DownInput,
        NoInput
    };
    class Controlable : public ECS::MovableEntity {
        public:
            Controlable(){};
            ~Controlable(){};

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
        protected:
            ECS::InputType _input;
           
        private:
    };
}