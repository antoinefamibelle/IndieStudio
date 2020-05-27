/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Entity
*/

#pragma once

#include "Static.hpp"

namespace ECS {
    class StaticEntity : public ECS::Static{
        public:
            StaticEntity();
            ~StaticEntity();


            bool isAlive() { return !this->_isAlive; };
            bool canMove() { return this->_canMove; };
            bool canBeDestroy() {return this->_canBeDestroy; };
            bool checkUpdate();
            void update();
        protected:
            bool _isAlive;
            bool _canMove;
            bool _canUpdate;
            bool _canBeDestroy;
        private:
    };
}
