/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Object
*/

#pragma once

namespace ECS {

    enum ObjectType {
        CharacterType,
        BombType,
        WallType,
        UnbreakableWallType,
        FloorType,
        UndefinedType
    };

    class Object {
        public:
            Object();
            ~Object();

            virtual void init();
            virtual void update();

            bool isEmpty() {return this->_isEmpty; };
            int getId() {return this->_id;};
            int getPosX() {return this->_x; };
            int getPosY() {return this->_y; };
            ECS::ObjectType getType() {return this->_objectType; };

            void setEmpty(bool empty) {this->_isEmpty = empty; };  
            void setId(int id) {this->_id = id; };
            void setPoxX(int x) {this->_x = x; };
            void setPosY(int y) {this->_y = y; };
            void setType(ECS::ObjectType type) {this->_objectType = type; };
        protected:
            ECS::ObjectType _objectType;
            int _id;
            int _x;
            int _y;
            bool _isEmpty;
        private:
    };
}
