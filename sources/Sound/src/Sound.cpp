/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Sound
*/

#include "Sound.hpp"

Sound::Sound()
{
}

Sound::~Sound()
{
}

void Sound::gameMusic()
{
    if (!this->_game.openFromFile("./Assets/sound/game.ogg"))
        throw "Impossible to load a Music";
    this->_game.setLoop(true);
    this->_game.play();
}

void Sound::bombExplosionEffect()
{
    if (!this->_bomb.openFromFile("./Assets/sound/music.ogg"))
        throw "Impossible to load a Music";
    this->_bomb.play();
}

void Sound::menuMusic()
{
    if (!this->_menu.openFromFile("./Assets/sound/menu.ogg"))
        throw "Impossible to load a Music";
    this->_menu.setLoop(true);
    this->_menu.play();
}

void Sound::menuArrowEffect()
{
    if (!this->_arrow.openFromFile("./Assets/sound/click1.ogg"))
        throw "Impossible to load a Music";
    this->_arrow.play();
}

void Sound::menuEnterEffect()
{
    if (!this->_arrow.openFromFile("./Assets/sound/click2.ogg"))
        throw "Impossible to load a Music";
    this->_arrow.play();
}

void Sound::menuMusicStop()
{
    this->_menu.stop();
}

void Sound::gameMusicStop()
{
    this->_game.stop();
}
