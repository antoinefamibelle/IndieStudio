/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** AObject
*/

#pragma once

#include "iostream"
#include "memory"
#include "vector"
#include "string"


namespace ECS {
    enum ObjectType {
        CharacterType,
        BombType,
        WallType,
        UnbreakableWallType,
        FloorType,
        UndefinedType
    };

    class AObject {
        public:
            AObject(){};
            ~AObject(){};

            virtual bool isEmpty() = 0;
            virtual int getId() = 0;
            virtual int getPosX() = 0;
            virtual int getPosY() = 0;
            virtual ECS::ObjectType getType() = 0;

            virtual void setEmpty(bool empty) = 0;  
            virtual void setId(int id) = 0;
            virtual void setPosX(int x) = 0;
            virtual void setPosY(int y) = 0;
            virtual void setType(ECS::ObjectType type) = 0;

        protected:
        private:
    };
}
