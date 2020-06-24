/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Bomb
*/

#include "Bomb.hpp"

ECS::Bomb::Bomb(irr::scene::ISceneManager *sceneManager, IrrlichtDevice *device)
{
    this->_time = 5;
    this->_range = 1;
    this->_busy = false;
    this->_chrono = new Chrono();
    _device = device;
    _sceneManager = sceneManager;
}

ECS::Bomb::~Bomb()
{
    _sceneManager->addToDeletionQueue(_meshNode);
    _triangleSelector->drop();
}

void ECS::Bomb::reduceTime()
{
    if (this->_time >= 3) {
        this->_time -= 1;
    }
}

void ECS::Bomb::addPower()
{
    this->_range += 1;
}

void ECS::Bomb::pose(int x, int y)
{
    if (this->_busy == true) {
        return;
    }
    std::cout << "Bomb posée: (x: " << x << ", y: " << y << ")" << std::endl;
    this->_busy = true;
    this->_actualTime = this->getTime();
    this->setCoord(x, y);
    this->graphicPose();
}

bool ECS::Bomb::isTicking()
{
    if (this->_busy == false)
        return false;
    if (this->_chrono->getElapsedTime() < this->getTime()) {
        return true;
    }
    return false;
}

void ECS::Bomb::checkBomb()
{
    if (this->_busy == false)
        return;
    if (this->_actualTime <= 1) {
        std::cout << "Explosion" << std::endl;
    }
}

void ECS::Bomb::graphicPose()
{
    if (_meshNode = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./Assets/3d/bomb.3DS"))) {
        _triangleSelector = _sceneManager->createOctreeTriangleSelector(_meshNode->getMesh(), _meshNode, 128);
        _meshNode->setTriangleSelector(_triangleSelector);
    }
    _meshNode->setPosition(vector3df(50 * (_y - 6), 20, -50 * (_x - 5) + 50));
    _meshNode->setMaterialFlag(EMF_LIGHTING, false);
}

void ECS::Bomb::graphicExplode()
{
    Explosion *exploOne = new Explosion(_device, _x, _y, vector3df(0, 0, 0.45), _range);
    Explosion *exploTwo = new Explosion(_device, _x, _y, vector3df(0, 0, -0.45), _range);
    Explosion *exploThree = new Explosion(_device, _x, _y, vector3df(-0.45, 0, 0), _range);
    Explosion *exploFour = new Explosion(_device, _x, _y, vector3df(0.45, 0, 0), _range);

    // Delete les 4 explosions avec un chrono, au bout de ~0.2 secondes :

    // delete exploOne;
    // delete exploTwo;
    // delete exploThree;
    // delete exploFour;

    _meshNode->remove();
    _busy = false;
}