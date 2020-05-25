/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Controlable
*/

#pragma once

#include "Movable.hpp"

namespace ECS {
    enum InputType {
        LeftInput,
        RightInput,
        UpInput,
        DownInput,
        NoInput
    };
    class Controlable : public ECS::Movable {
        public:
            Controlable();
            ~Controlable();

        protected:
            ECS::InputType _input;
        private:
    };
}