/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

#include <unistd.h>
#include <cstdlib>
#include <algorithm>
#include "Character.hpp"
#include "FileManagement.hpp"
#include "Bomb.hpp"

namespace ECS {
    class AI : public ECS::Character {
        public:
            AI();
            ~AI();
            void runAI();
            void findClosestEnemy();
            void findDir();
            void moveAI();
            void findSafePlace();
            bool isInBombRange(int, int);
            bool isInLastPositions(std::vector<std::pair<int, int>>, std::pair<int, int>);
            void goToSafePlace();
            bool isInEnemyRange();

        protected:
        private:
            std::vector<std::string> _map;
            ECS::Direction _dir;
            std::pair<int, int> _closestEnemyPos;
            std::pair<int, int> _safePlacePos;
            bool _safePlaceFound;
            bool _isRunningAway;
            std::vector<std::pair<int, int>> _pathToSafePlace;
            // Pour les tests (à remplacer par la vraie range de la bombe):
            int _bombRange;
    };
}

#endif /* !AI_HPP_ */