/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Character
*/

#include "Character.hpp"
#include "Object.hpp"

ECS::Character::Character(int startX, int startY, int id, IrrlichtDevice *device, ISceneManager *sceneManager)
{
    this->setPosX(startX);
    this->setPosY(startY);
    this->setId(id);
    this->setType(ECS::CharacterType);
    this->_isAlive = true;

    _device = device;
    _sceneManager = sceneManager;
    if (_model = _device->getSceneManager()->addAnimatedMeshSceneNode(_device->getSceneManager()->getMesh("./Assets/3d/player.md2"))) {
        _model->setMaterialTexture(0, _device->getVideoDriver()->getTexture("./Assets/3d/player.bmp"));
        _model->setMD2Animation(scene::EMAT_STAND);
        _model->setMaterialFlag(EMF_LIGHTING, false);
        _model->setPosition(vector3df(50 * (_y - 6), 30, -50 * (_x - 5) + 50));
        _model->setName("Player");
        _triangleSelector = _device->getSceneManager()->createOctreeTriangleSelector(_model->getMesh(), _model, 128);
        _model->setTriangleSelector(_triangleSelector);
    }
    this->_bomb = new Bomb(_sceneManager, _device);
}

ECS::Character::~Character()
{
    _device->getSceneManager()->addToDeletionQueue(_model);
    _model->removeAnimators();
    _triangleSelector->drop();
}

void ECS::Character::graphicMove(ECS::Direction dir)
{
    _model->setPosition(vector3df(50 * (getPosY() - 6), 30, -50 * (getPosX() - 5) + 50));
    _model->setMD2Animation(EMAT_RUN);
    if (dir == UP)
        _model->setRotation(vector3df(0.0, 270.0, 0.0));
    else if (dir == DOWN)
        _model->setRotation(vector3df(0.0, 90.0, 0.0));
    else if (dir == LEFT)
        _model->setRotation(vector3df(0.0, 180.0, 0.0));
    else if (dir == RIGHT)
        _model->setRotation(vector3df(0.0, 0.0, 0.0));
}

void ECS::Character::graphicStand()
{
    _model->setMD2Animation(irr::scene::EMAT_STAND);
}

void ECS::Character::setDeath()
{
    this->_isAlive = false;
}

void ECS::Character::explose(std::vector<std::string> map, std::vector<ECS::Character *> players)
{
    _bomb->graphicExplode();
    for (int i = 0; i < this->getBomb()->getRange(); i++) {
        if (map[this->getBomb()->getPosX()][this->getBomb()->getPosY() + i]) {
            for (auto &j: players) {
                if (j->getPosY() == this->getBomb()->getPosY() + i && j->getPosX() == this->getBomb()->getPosX())
                    j->setIsALive(false);
            }
            if (map[this->getBomb()->getPosX()][this->getBomb()->getPosY() + i] == 'X') {
                map[this->getBomb()->getPosX()][this->getBomb()->getPosY() + i] = ' ';
                break;
            }
        }
    }
    for (int i = 0; i < this->getBomb()->getRange(); i++) {
        if (map[this->getBomb()->getPosX() + i][this->getBomb()->getPosY()]) {
            for (auto &j: players) {
                if (j->getPosY() == this->getBomb()->getPosY() && j->getPosX() == this->getBomb()->getPosX() + i)
                    j->setIsALive(false);
            }
            if (map[this->getBomb()->getPosX() + i][this->getBomb()->getPosY()] == 'X') {
                map[this->getBomb()->getPosX() + i][this->getBomb()->getPosY()] = ' ';
                break;
            }
        }
    }
}

bool ECS::Character::isTicking()
{
    if (this->getBomb()->isTicking() == true) {
        return true;
    }
    return false;
}