/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Character
*/

#include "Character.hpp"
#include "Object.hpp"

ECS::Character::Character(int x, int y, int id)
{
    this->setPoxX(x);
    this->setPosY(y);
    this->setId(id);
    this->setType(ECS::CharacterType);
}

ECS::Character::~Character()
{
    
}
