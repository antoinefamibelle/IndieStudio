/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** StaticEntity
*/

#include "StaticEntity.hpp"

ECS::StaticEntity::StaticEntity()
{
}

ECS::StaticEntity::~StaticEntity()
{
}

void ECS::StaticEntity::update()
{
    this->_isAlive = true;
    this->_canBeDestroy = false;
    this->setType(ECS::FloorType);
    this->setSprite();
}

bool ECS::StaticEntity::checkUpdate()
{
    if (this->_canUpdate == true) {
        if (this->_isAlive == false)
            return true;
        else
            return false;
    }
    return false;
}