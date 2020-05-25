/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Movable
*/

#include "Movable.hpp"

ECS::Movable::Movable()
{
}

ECS::Movable::~Movable()
{
}

void ECS::Movable::moveDown()
{
    this->_y += 1;
}

void ECS::Movable::moveUp()
{
    if (this->_y != 1) {
        this->_y -= 1;
    }
}

void ECS::Movable::moveLeft()
{
    if (this->_x != 1) {
        this->_x -= 1;
    }
}

void ECS::Movable::moveRight()
{
    this->_x += 1;
}
