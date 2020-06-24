/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <SFML/Audio.hpp>

class Sound {
    public:
        Sound();
        ~Sound();

        void gameMusic();
        void bombExplosionEffect();

        void menuMusic();       
        void menuArrowEffect();
        void menuEnterEffect();
        void menuMusicStop();
        void gameMusicStop();
    protected:
        sf::Music _menu;
        sf::Music _game;
        sf::Music _bomb;
        sf::Music _arrow;
    private:

};

#endif /* !SOUND_HPP_ */
