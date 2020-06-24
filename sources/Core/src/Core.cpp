/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Core
*/

#include "Core.hpp"
#include "Wall.hpp"
#include "Floor.hpp"

Indie::Core::Core(int nbPlayers)
{
    this->_score = 0;
    this->_numberOfPlayer = nbPlayers;
    // 25 A MOVE 
    this->mapGenerator.genMap(nbPlayers, 25);
}

Indie::Core::~Core()
{
}

void Indie::Core::printMapInfo()
{
    /*for (auto &i : this->_map) {
        i.first->getInfo();
    }*/
}

void Indie::Core::run()
{
    for (int i = 0; i != 10; i ++) {
        std::shared_ptr<ECS::StaticEntity> tmp;
        this->_map.push_back(make_pair(tmp,i));
    }
}