/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** MyIrrlicht
*/

#include "MyIrrlicht.hpp"


MyIrrlicht::MyIrrlicht()
{
    this->_chrono = new Chrono();
    this->_chrono->startChrono();
    this->_sound = new Sound();
}

MyIrrlicht::~MyIrrlicht()
{
}

void MyIrrlicht::printText(std::string str, int x, int y)
{
    this->_environnement->drawAll();
    this->_font->draw(L"WEWE",core::rect<s32>(130,10,300,200),
                                     video::SColor(255,255,255,255));
}


void MyIrrlicht::initWindow(int sizeX, int sizeY)
{
    this->_device = createDevice(EDT_OPENGL, core::dimension2d<u32>(sizeX, sizeY), 16, false, false, false, &this->_receiver);
    if (_device == 0)
        throw "Error on creation of the device";
    this->_device->setWindowCaption(L"Indie Studio [EPITECH]");
    this->_device->setResizable(true);
    this->_driver = this->_device->getVideoDriver();
    this->_sceneManager = this->_device->getSceneManager();
    this->_environnement = this->_device->getGUIEnvironment();
    this->_skin = this->_environnement->getSkin();
    this->_font = this->_environnement->getFont("./Assets/fonts/Fonts.ttf");
    if (this->_font)
        this->_skin->setFont(this->_font);
}

int MyIrrlicht::getMenuInput()
{
    if (this->_chrono->getElapsedTime() < 0.2)
        return 84;
    if (this->_receiver.IsKeyDown(irr::KEY_UP)) {
        this->_chrono->resetChrono();
        this->_sound->menuArrowEffect();
        return -1;
    } else if(this->_receiver.IsKeyDown(irr::KEY_DOWN)) {
        this->_chrono->resetChrono();
        this->_sound->menuArrowEffect();
        return 1;
    } else if(this->_receiver.IsKeyDown(irr::KEY_RETURN)) {
        this->_chrono->resetChrono();
        this->_sound->menuEnterEffect();
        return 2;
    }else if(this->_receiver.IsKeyDown(irr::KEY_LEFT)) {
        this->_chrono->resetChrono();
        this->_sound->menuArrowEffect();
        return -3;
    } else if(this->_receiver.IsKeyDown(irr::KEY_RIGHT)) {
        this->_chrono->resetChrono();
        this->_sound->menuArrowEffect();
        return 3;
    }
    return 84;
}

int MyIrrlicht::getPlayersInput(std::vector<std::pair<enum irr::EKEY_CODE, int>> playerKeys) const
{
    for (auto &i: playerKeys) {
        if (this->_receiver.IsKeyDown(i.first))
            return i.second;
    }
    return 0;
}

std::map<int, std::vector<std::pair<enum irr::EKEY_CODE, int>>> MyIrrlicht::createMap()
{
    std::map<int, std::vector<std::pair<enum irr::EKEY_CODE, int>>> _map;
    std::vector<std::pair<enum irr::EKEY_CODE, int>> tmp;

    tmp.push_back(std::make_pair(irr::KEY_KEY_Z, -1));
    tmp.push_back(std::make_pair(irr::KEY_KEY_Q, -2));
    tmp.push_back(std::make_pair(irr::KEY_KEY_S, 1));
    tmp.push_back(std::make_pair(irr::KEY_KEY_D, 2));
    tmp.push_back(std::make_pair(irr::KEY_KEY_A, 3));

    _map.insert(std::pair<int, std::vector<std::pair<enum irr::EKEY_CODE, int>>>(0, tmp));
    tmp.erase(tmp.begin(), tmp.end());

    tmp.push_back(std::make_pair(irr::KEY_UP, -1));
    tmp.push_back(std::make_pair(irr::KEY_LEFT, -2));
    tmp.push_back(std::make_pair(irr::KEY_DOWN, 1));
    tmp.push_back(std::make_pair(irr::KEY_RIGHT, 2));
    tmp.push_back(std::make_pair(irr::KEY_RETURN, 3));

    _map.insert(std::pair<int, std::vector<std::pair<enum irr::EKEY_CODE, int>>>(1, tmp));
    tmp.erase(tmp.begin(), tmp.end());

    tmp.push_back(std::make_pair(irr::KEY_KEY_T, -1));
    tmp.push_back(std::make_pair(irr::KEY_KEY_F, -2));
    tmp.push_back(std::make_pair(irr::KEY_KEY_G, 1));
    tmp.push_back(std::make_pair(irr::KEY_KEY_H, 2));
    tmp.push_back(std::make_pair(irr::KEY_KEY_Y, 3));

    _map.insert(std::pair<int, std::vector<std::pair<enum irr::EKEY_CODE, int>>>(2, tmp));
    tmp.erase(tmp.begin(), tmp.end());

    tmp.push_back(std::make_pair(irr::KEY_KEY_I, -1));
    tmp.push_back(std::make_pair(irr::KEY_KEY_J, -2));
    tmp.push_back(std::make_pair(irr::KEY_KEY_K, 1));
    tmp.push_back(std::make_pair(irr::KEY_KEY_L, 2));
    tmp.push_back(std::make_pair(irr::KEY_KEY_O, 3));

    _map.insert(std::pair<int, std::vector<std::pair<enum irr::EKEY_CODE, int>>>(3, tmp));
    tmp.erase(tmp.begin(), tmp.end());

    return _map;
}
