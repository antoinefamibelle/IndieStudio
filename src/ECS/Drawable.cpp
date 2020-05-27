/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Drawable
*/

#include "Drawable.hpp"

ECS::Drawable::Drawable()
{
}

ECS::Drawable::~Drawable()
{
}

void ECS::Drawable::setSprite()
{
    if (this->getType() == ECS::FloorType) {
        std::cout << "sprite Floor" << std::endl;
    }
    else if (this->getType() == ECS::BombType) {
        std::cout << "sprite Bomb" << std::endl;
    }
    else if (this->getType() == ECS::CharacterType) {
        std::cout << "sprite Bomb" << std::endl;
    }
     else if (this->getType() == ECS::UnbreakableWallType) {
        std::cout << "sprite Bomb" << std::endl;
    }
     else if (this->getType() == ECS::WallType) {
        std::cout << "sprite Bomb" << std::endl;
    }
    else {
        std::cout << "Il doit y avoir un probleme de type" << std::endl;
    }
}