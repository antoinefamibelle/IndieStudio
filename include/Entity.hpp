/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Entity
*/

#pragma once

#include "iostream"

namespace Indie {
    enum EntityType {
        CharacterType,
        BombType,
        WallType,
        UnbreakableWallType,
        FloorType,
        UndefinedType
    };

    class Entity {
        public:
            Entity();
            ~Entity();

            void getInfo();
            int getPosX() { return this->_posX; };
            int getPosY() { return this->_posY; };
            int getLife() { return this->_life; };
            Indie::EntityType getType() { return this->_type; };
            std::string getPos() {return "Position X : " + std::to_string(this->_posX) + "Position Y : " + std::to_string(this->getPosY());}

        protected:
            int _posX;
            int _posY;
            Indie::EntityType _type;
            int _life;
            int _id;
        private:
    };
}