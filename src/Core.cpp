/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Core
*/

#include "Core.hpp"
#include "Wall.hpp"
#include "Floor.hpp"

Indie::Core::Core(int nb)
{
    this->_score = 0;
    this->_numberOfPlayer = nb;
}

Indie::Core::~Core()
{
}

void Indie::Core::printMapInfo()
{
    for (auto &i : this->_map) {
        i.first->getInfo();
    }
}