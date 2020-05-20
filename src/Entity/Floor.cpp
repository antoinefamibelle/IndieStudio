/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Floor
*/

#include "Floor.hpp"

Indie::Floor::Floor(int x, int y, int id)
{
    this->_posX = x;
    this->_posY = y;
    this->_id = id;
    this->_type = Indie::FloorType;
}

Indie::Floor::~Floor()
{
}

