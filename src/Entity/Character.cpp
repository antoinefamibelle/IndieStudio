/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Character
*/

#include "Character.hpp"

Indie::Character::Character(int x, int y, int id)
{
    this->_posX = x;
    this->_posY = y;
    this->_id = id;
    this->_type = Indie::CharacterType;
}

Indie::Character::~Character()
{
    
}
