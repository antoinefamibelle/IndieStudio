/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Wall
*/

#include "Wall.hpp"

ECS::Wall::Wall(int x, int y, int id, ECS::ObjectType type)
{
    this->setId(id);
    this->setPosY(y);
    this->setPoxX(x);
    this->setType(type);
}

ECS::Wall::~Wall()
{
}
