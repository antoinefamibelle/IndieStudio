/*
** EPITECH PROJECT, 2020
** Indie Studio
** File description:
** MapGenerator
*/

#ifndef MAPGENERATOR_HPP_
#define MAPGENERATOR_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#define RAND_BASIC_LINE rand() % mapSize + 1
#define RAND_PLAYER_LINE rand() % ((mapSize - 3) - 4 + 1) + 4

class MapGenerator {
    public:
        MapGenerator();
        ~MapGenerator();
        int genMap(int, int);
        void initMap(int);
        void handleWalls(int);
        void placePlayers(int, int);
        int writeInFile();

    private:
        std::vector<std::string> _map;
};

#endif /* !MAPGENERATOR_HPP_ */