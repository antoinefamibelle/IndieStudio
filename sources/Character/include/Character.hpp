/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Character
*/

#pragma once

#include "Chrono.hpp"
#include "Controlable.hpp"
#include "Object.hpp"
#include <irrlicht.h>
#include "Bomb.hpp"

using namespace irr;
using namespace scene;
using namespace video;
using namespace core;

namespace ECS {
    class Character : public ECS::Controlable {
        public:
            Character(int, int, int, IrrlichtDevice *, ISceneManager *);
            ~Character();

            void graphicMove(ECS::Direction);
            void graphicStand();
            bool isTicking();
            void explose(std::vector<std::string> map, std::vector<ECS::Character *> players);
            bool isBombReady() { return this->_bombReady; };
            void setIsALive(bool isALive) { this->_isAlive = isALive; };
            bool isAlive() {return this->_isAlive; };
            void setDeath();
            ECS::Bomb *getBomb() { return this->_bomb; };
        protected:
            bool _bombReady;
            Chrono _chrono;
            bool _isAlive;
            ECS::Bomb *_bomb;
            IrrlichtDevice *_device;
            IAnimatedMeshSceneNode *_model;
            ITriangleSelector *_triangleSelector;
            ISceneManager *_sceneManager;
    };
}
