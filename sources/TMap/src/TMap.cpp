/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** 3dMap
*/

#include "TMap.hpp"

TMap::TMap(IrrlichtDevice *device) : _irrDevice(device), _sceneManager(device->getSceneManager())
{
    array<ISceneNode *>	nodes;

    if (_sceneManager->loadScene("./Assets/maps/map.irr")) {
        _metaTriangleSelector = _sceneManager->createMetaTriangleSelector();
        _sceneManager->getSceneNodesFromType(ESNT_CUBE, nodes);
        _sceneManager->addCameraSceneNode(NULL, vector3df(0, 450, -200), vector3df(0, 0, 0));
        for (int i = 0; i < nodes.size(); ++i) {
            if (_triangleSelector = _sceneManager->createTriangleSelectorFromBoundingBox(nodes[i])) {
                _metaTriangleSelector->addTriangleSelector(_triangleSelector);
                _triangleSelector->drop();
            }
        }
    }
}

TMap::~TMap()
{
    _metaTriangleSelector->drop();
}

std::vector<std::string> TMap::createWallArray(std::vector<std::string> textMap)
{
    srand(time(NULL));
    for (int x = 0; x < textMap.size(); ++x) {
        for (int y = 0; y < textMap[x].size(); ++y) {
            if (textMap[x][y] == 'O' && rand() % 2 == 0) {
                new ECS::Wall(_irrDevice, vector3df(50 * (y - 6), 30, 50 * (x - 5) + 50));
                textMap[x][y] = '#';
            }
        }
    }
    return textMap;
}