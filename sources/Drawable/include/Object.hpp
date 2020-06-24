/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Object
*/

#pragma once

#include "AObject.hpp"

namespace ECS {
    class Object : public AObject{
        public:
            Object(){};
            ~Object(){};

            bool isEmpty() { return this->_isEmpty; };
            int getId() { return this->_id;};
            int getPosX() { return this->_x; };
            int getPosY() { return this->_y; };
            ECS::ObjectType getType() { return this->_objectType; };

            void setEmpty(bool empty) { this->_isEmpty = empty; };  
            void setId(int id) { this->_id = id; };
            void setPosX(int x) { this->_x = x; };
            void setPosY(int y) { this->_y = y; };
            void setType(ECS::ObjectType type) { this->_objectType = type; };
        protected:
            ECS::ObjectType _objectType;
            int _id;
            int _x;
            int _y;
            bool _isEmpty;
        private:
    };
}
