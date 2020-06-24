/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Bomb
*/

#pragma once

#include "vector"
#include "memory"
#include "Static.hpp"
#include "Chrono.hpp"
#include "Explosion.hpp"
#include <irrlicht.h>

using namespace irr;
using namespace scene;
using namespace video;
using namespace core;

namespace ECS {
    class Bomb : public ECS::Static {
         public:
            Bomb(ISceneManager *, IrrlichtDevice *);
            ~Bomb();

            void updateBomb();
            int getRange() { return this->_range; };
            int getTime() { return this->_time; };
            int getId() { return this->_id; };
            int getPosX() { return this->_x; };
            int getPosY() { return this->_y; };

            bool isTicking();
            bool isBusy() { return this->_busy; };
            void setCoord(int x, int y) { this->_x = x; this->_y = y; };
            void setId(int id) { this->_id = id; };
           
            void checkBomb();
            void reduceTime();
            void addPower();
            void pose(int, int);

            void graphicPose();
            void graphicExplode();

        protected:
            int _id;
            int _time;  // Temps avant l'explosion
            int _range; // Taille de l'explosion
            int _actualTime;
            Chrono *_chrono;
            bool _busy;
            int _x;
            int _y;
            // boost::thread_group _thread;
            IrrlichtDevice *_device;
            IAnimatedMeshSceneNode *_meshNode;
            ITriangleSelector *_triangleSelector;
            ISceneManager *_sceneManager;

        private:
    };
}
