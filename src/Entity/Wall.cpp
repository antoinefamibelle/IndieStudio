/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Wall
*/

#include "Wall.hpp"

Indie::Wall::Wall(int x, int y, int id, Indie::EntityType type)
{
    this->_life = 50;
    this->_posY = y;
    this->_posX = x;
    this->_bomb = false;
    this->_id = id;
    this->_type = type;
}

Indie::Wall::~Wall()
{
}
