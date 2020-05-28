/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Floor
*/

#pragma once

#include "Static.hpp"
#include "Object.hpp"

namespace ECS {
    class Floor : public ECS::Static {
        public:
            Floor(int, int, int);
            ~Floor();
        protected:
        private:
    };
}