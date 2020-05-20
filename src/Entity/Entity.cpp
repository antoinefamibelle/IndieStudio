/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Entity
*/

#include "Entity.hpp"

Indie::Entity::Entity()
{
}

Indie::Entity::~Entity()
{
}

void Indie::Entity::getInfo()
{
    if (this->_type == Indie::EntityType::BombType) {
        std::cout << "A la position X : " << this ->_posX << " et Y : " << this->_posY << " = BOMBE" << std::endl;
    }
    else if (this->_type == Indie::EntityType::WallType) {
        std::cout << "A la position X : " << this ->_posX << " et Y : " << this->_posY << " = Wall" << std::endl;
    }
    else if (this->_type == Indie::EntityType::CharacterType) {
        std::cout << "A la position X : " << this ->_posX << " et Y : " << this->_posY << " = Personnage" << std::endl;
    }
    else if (this->_type == Indie::EntityType::UnbreakableWallType) {
        std::cout << "A la position X : " << this ->_posX << " et Y : " << this->_posY << " = WALL UNBREAK" << std::endl;
    }
    else if (this->_type == Indie::EntityType::FloorType) {
        std::cout << "A la position X : " << this ->_posX << " et Y : " << this->_posY << " = FLOOR" << std::endl;
    }
}