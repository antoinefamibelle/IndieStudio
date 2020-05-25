/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Bomb
*/

#include "Bomb.hpp"

ECS::Bomb::Bomb()
{
    this->_time = 5;
    this->_range = 1;
    this->_busy = false;
}

void ECS::Bomb::reduceTime()
{
    if (this->_time >= 3) {
        this->_time -= 1;
    }
}

void ECS::Bomb::addPower()
{
    this->_range += 1;
}

bool ECS::Bomb::pose(std::vector<std::shared_ptr<ECS::Object>> map, int x, int y)
{
    if (this->_busy == true) {
        return false;
    }
    for (auto &i : map) {
        if (i->getPosX() == x && i->getPosY() == y) {
            if (i->getType() == ECS::FloorType) {
                if (i->isEmpty() == true) {
                    return true;
                }
                else
                    return false;
            }
            else
                    return false;
        }
    }
    return false;
}

void ECS::Bomb::lauchBomb()
{
    this->_thread.create_thread(boost::bind())
}