/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Floor
*/

#include "Floor.hpp"

ECS::Floor::Floor(int x, int y, int id)
{
    this->setPoxX(x);
    this->setPosY(y);
    this->setId(id);
    this->setType(ECS::ObjectType::FloorType);
    this->setEmpty(true);
}

ECS::Floor::~Floor()
{
}

