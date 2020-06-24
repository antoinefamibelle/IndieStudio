/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Wall
*/

#include <algorithm>
#include "Wall.hpp"

ECS::Wall::Wall(irr::IrrlichtDevice *irrDevice, irr::core::vector3df const &position) : _sceneManager(irrDevice->getSceneManager()), _position(position)
{
    // this->setId(id);
    // this->setPosY(y);
    // this->setPosX(x);
    // this->setType(type);
    _wall = _sceneManager->addCubeSceneNode(50.f, NULL, -1, position);
    _wall->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _wall->setMaterialTexture(0, irrDevice->getVideoDriver()->getTexture("./Assets/images/wood.png"));
    _wall->setTriangleSelector(_triangleSelector = _sceneManager->createOctreeTriangleSelector(_wall->getMesh(), _wall, 128));
}

ECS::Wall::~Wall()
{
    _sceneManager->addToDeletionQueue(_wall);
    _triangleSelector->drop();
}