/*
** EPITECH PROJECT, 2020
** Indie Studio
** File description:
** MapGenerator
*/

#include <ctime>
#include "MapGenerator.hpp"

MapGenerator::MapGenerator() {}
MapGenerator::~MapGenerator() {}

int MapGenerator::genMap(int nbPlayers, int mapSize)
{
    if (nbPlayers < 1 || nbPlayers > 4 || mapSize < 12)
        return 84;
    srand(time(NULL));
    initMap(mapSize);
    handleWalls(mapSize);
    placePlayers(nbPlayers, mapSize);
    return writeInFile();
}

void MapGenerator::initMap(int mapSize)
{
    std::string limitsLine;
    std::string floorLine("0");
    std::string wallsLine;

    for (int i = 0; i < mapSize + 2; ++i)
        limitsLine += '0';
    for (int i = 0; i < mapSize; ++i)
        floorLine += '1';
    floorLine += '0';
    wallsLine = floorLine;
	for (size_t pos; (pos = wallsLine.find('1')) != std::string::npos;)
		wallsLine.replace(pos, 1, "2");
    _map.push_back(limitsLine);
    for (int i = 0; i < mapSize; ++i) {
        if (i % 2 == 0 || i == mapSize - 1)
            _map.push_back(floorLine);
        else
            _map.push_back(wallsLine);
    }
    _map.push_back(limitsLine);
}

void MapGenerator::handleWalls(int mapSize)
{
    std::vector<int> indexes;
    int tmp = 0;

    for (int i = 1; i <= mapSize; ++i) {
        for (int idx = 0; idx < 6; ++idx) {
            tmp = (i == 1 || i == mapSize) ? RAND_PLAYER_LINE : RAND_BASIC_LINE;
            while (std::find(indexes.begin(), indexes.end(), tmp) != indexes.end())
                tmp = (i == 1 || i == mapSize) ? RAND_PLAYER_LINE : RAND_BASIC_LINE;
            indexes.push_back(tmp);
        }
        for (size_t idx = 0; idx < indexes.size(); ++idx)
            _map[i][indexes.at(idx)] = (i % 2 != 0 || i == mapSize) ? '2' : '1';
        indexes.clear();
    }
}

void MapGenerator::placePlayers(int nbPlayers, int mapSize)
{
    _map[1][1] = _map[1][mapSize] = _map[mapSize][1] =
    _map[mapSize][mapSize] = 'A';
    if (nbPlayers >= 1)
        _map[1][1] = 'P';
    if (nbPlayers >= 2)
        _map[1][mapSize] = 'P';
    if (nbPlayers >= 3)
        _map[mapSize][1] = 'P';
    if (nbPlayers == 4)
        _map[mapSize][mapSize] = 'P';
}

void closeFile(FILE *filePtr)
{
    if (filePtr != nullptr)
        fclose(filePtr);
}

int MapGenerator::writeInFile()
{
    FILE *file = fopen("map.conf", "w");
    std::shared_ptr<FILE> filePtr(file, closeFile);

    if (filePtr == nullptr)
        return 84;
    for (size_t i = 0; i < _map.size(); ++i)
        fprintf(file, "%s\n", _map[i].c_str());
    return 0;
}

int main(int ac, char **av)
{
    MapGenerator mapGenerator;

    if (ac != 3)
        return 84;
    if (mapGenerator.genMap(atoi(av[1]), atoi(av[2])) == 84)
        return 84;
    return 0;
}