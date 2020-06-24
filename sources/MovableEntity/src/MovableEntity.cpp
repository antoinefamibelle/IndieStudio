/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** MovableEntity
*/

#include "MovableEntity.hpp"

ECS::MovableEntity::MovableEntity()
{

}

ECS::MovableEntity::~MovableEntity()
{
}

bool ECS::MovableEntity::canMove(enum Direction direction, std::vector<std::string> map)
{
    if (direction == UP) {
        if (getPosX() - 1 < 0)
            return false;
        else if (map[getPosX() - 1][getPosY()] == 'S' || map[getPosX() - 1][getPosY()] == 'O')
            return true;
    }
    if (direction == DOWN) {
        if (getPosX() + 1 > 10)
            return false;
        else if (map[getPosX() + 1][getPosY()] == 'S' || map[getPosX() + 1][getPosY()] == 'O')
            return true;
    }
    if (direction == LEFT) {
        if (getPosY() - 1 < 0)
            return false;
        else if (map[getPosX()][getPosY() - 1] == 'S' || map[getPosX()][getPosY() - 1] == 'O')
            return true;
    }
    if (direction == RIGHT) {
        if (getPosY() - 1 > 12)
            return false;
        else if (map[getPosX()][getPosY() + 1] == 'S' || map[getPosX()][getPosY() + 1] == 'O')
            return true;
    }
    return false;
}

bool ECS::MovableEntity::move(enum Direction direction, std::vector<std::string> map)
{
    if (this->canMove(direction, map) == false)
        return false;
    else if (direction == DOWN)
        this->setPosX(this->getPosX() + 1);
    else if (direction == UP)
        this->setPosX(this->getPosX() - 1);
    else if (direction == RIGHT)
        this->setPosY(this->getPosY() + 1);
    else if (direction == LEFT)
        this->setPosY(this->getPosY() - 1);
    return true;
}