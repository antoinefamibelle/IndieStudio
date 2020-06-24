/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** 3dMap
*/

#pragma once

#include "memory"
#include "vector"
#include "MyIrrlicht.hpp"
#include "Wall.hpp"

using namespace irr;
using namespace scene;
using namespace video;
using namespace core;

class TMap {
    public: 
        TMap(IrrlichtDevice *);
        ~TMap();
        std::vector<std::string> createWallArray(std::vector<std::string>);

    private:
        static char const *_baseMap[];
        ISceneManager *_sceneManager;
        IMetaTriangleSelector *_metaTriangleSelector;
        ITriangleSelector *_triangleSelector;
        IrrlichtDevice *_irrDevice;
        std::vector<std::string> _textMap;
};