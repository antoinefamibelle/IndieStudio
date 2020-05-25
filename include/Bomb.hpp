/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Bomb
*/

#pragma once

#include "Chrono.hpp"
#include "Static.hpp"
#include "vector"
#include "memory"
#include "boost/thread.hpp"

namespace ECS {
    class Bomb : public ECS::Static {
         public:
            Bomb();
            ~Bomb();

            int getRange() {return this->_range; };
            int getTime() {return this->_time; };
            bool isBusy() {return this->_busy; };

            void reduceTime();
            void addPower();
            bool pose(std::vector<std::shared_ptr<ECS::Object>> map, int x, int y);

            void lauchBomb();
            void waitBomb();

        protected:
            int _time;  // Temps avant l'explosion
            int _range; //taille de l'explosion
            Chrono _chrono;
            bool _busy;
            boost::thread_group _thread;
        private:
    };
}

