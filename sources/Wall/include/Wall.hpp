/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Wall
*/

#pragma once

#include <irrlicht.h>
#include <utility>
#include <vector>
#include "StaticEntity.hpp"
#include "Object.hpp"

using namespace irr;
using namespace scene;
using namespace video;
using namespace core;

namespace ECS {
    class Wall : public ECS::StaticEntity {
        public:
            Wall(IrrlichtDevice *, vector3df const &);
            ~Wall();
            // bool isAlive() { return !this->_isAlive; };

        // protected:
        //     bool _isAlive;

        private:
            typedef std::pair<IAnimatedMeshSceneNode *, ISceneNodeAnimator *> CollisionInfo;
            ISceneManager *_sceneManager;
            ITriangleSelector *_triangleSelector;
            IMeshSceneNode *_wall;
            std::vector<CollisionInfo> _collisionArray;
            vector3df _position;
    };
}