/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** MyIrrlicht
*/

#pragma once

#include "iostream"
#include "irr/irrlicht.h"
#include <unistd.h>
#include <iostream>
#include "Chrono.hpp"
#include "Sound.hpp"
#include <vector>
#include <map>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class MyEventReceiver : public IEventReceiver
{
    public:
        // This is the one method that we have to implement
        virtual bool OnEvent(const SEvent& event)
        {
            if (event.EventType == irr::EET_KEY_INPUT_EVENT)
                KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
            return false;
        }

        // This is used to check whether a key is being held down
        virtual bool IsKeyDown(EKEY_CODE keyCode) const {return KeyIsDown[keyCode];}
        
        MyEventReceiver()
        {
            for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
                KeyIsDown[i] = false;
        }

    private:
        // We use this array to store the current state of each key
        bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

class MyIrrlicht {
    public:
        MyIrrlicht();
        ~MyIrrlicht();

        std::map<int, std::vector<std::pair<enum irr::EKEY_CODE, int>>> createMap();
        void printText(std::string, int, int);
        int getMenuInput();
        int getPlayersInput(std::vector<std::pair<enum irr::EKEY_CODE, int>> playerKeys) const;
        void initWindow(int sizeX, int sizeY);
        void startScene() { _driver->beginScene(true, true, video::SColor(255,255,255,255)); };
	    void endScene() { _driver->endScene(); };
        ITexture *loadImage(std::string path) { ITexture *images = _driver->getTexture(path.c_str()); return images; };
        void draw(ITexture *images, int x, int y, int sizeX, int sizeY) { _driver->draw2DImage(images, core::position2d<s32>(x,y), core::rect<s32>(0,0,sizeX,sizeY), 0, video::SColor(255,255,255,255), true); };
        bool isWindowOpen() { return _device->run() ? true : false; };
        IrrlichtDevice *getDevice() {return this->_device; };
        ISceneManager *getScene() { return this->_sceneManager; };
        IGUIEnvironment *getEnv() {return this->_environnement;};
        IVideoDriver *getDriver() {return this->_driver; };

    // protected:
        IGUIFont *_font;
        Sound *_sound;
        IrrlichtDevice *_device;
        IVideoDriver *_driver;
        ISceneManager *_sceneManager;
        IGUIEnvironment *_environnement;
        IGUISkin *_skin;
        MyEventReceiver _receiver;
        Chrono *_chrono;
    private:
};