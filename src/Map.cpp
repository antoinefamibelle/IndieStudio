/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Map
*/

#include "Map.hpp"

Indie::Map::Map()
{
}

Indie::Map::~Map()
{
}

/*
void Indie::Map::printMapInfo()
{
    for (auto &i : this->_map) {
        if (i.first->getType() == Indie::EntityType::FloorType) {
            std::cout << i.first->getPos() << " = Floor" << std::endl;
        }
        else if (i.first->getType() == Indie::EntityType::WallType) {
            std::cout << i.first->getPos() << " = Wall" << std::endl;
        }
    }
}

std::vector<std::string> Indie::Map::openFile()
{
    std::string buffer;
    std::vector<std::string> map;

    this->_inFile.open("assets/map.txt");
    if (!this->_inFile) {
        throw "[CRITICAL ERROR] ! Impossible to find / Open the file assets/map.txt";
    }
    while (this->_inFile >> buffer) {
        map.push_back(buffer);
    }
    this->_inFile.close();
    return map;
}

std::vector<std::pair<Indie::Entity *,int> > Indie::Map::GenerateMap()
{
    std::vector<std::string> firstMap = this->openFile();
    int y = 0;
    int id = 0;

    for (auto &i : firstMap) {
        for (int x = 0; x != i.size(); x += 1) {
            if (i[x] == '0') {
                Indie::Wall *wall = new Indie::Wall(x, y, id, Indie::EntityType::UnbreakableWallType);
                this->_map.push_back(std::make_pair(wall,id));
            }
            else if (i[x] == '1') {
                Indie::Floor *floor = new Indie::Floor(x,y,id);
                this->_map.push_back(std::make_pair(floor,id));
            }
            else if (i[x] == '2') {
                Indie::Wall *wall = new Indie::Wall(x, y, id, Indie::EntityType::WallType);
                this->_map.push_back(std::make_pair(wall,id));
            }
            id += 1;
        }
        y += 1;
    }
    return this->_map;
}
*/