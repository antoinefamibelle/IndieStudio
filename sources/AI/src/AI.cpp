/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** AI
*/

#include "AI.hpp"

ECS::AI::AI() : ECS::Character::Character(_x, _y, _id, _device, _sceneManager)
{
    _isRunningAway = false;
    _safePlaceFound = false;
    // Pour les tests (à remplacer par la vraie range de la bombe):
    _bombRange = 5;
}

ECS::AI::~AI() {}

void ECS::AI::runAI()
{
    FileManagement fileManagement;

    _map = fileManagement.readFile("./Assets/maps/map.txt");
    if (_isRunningAway == false) {
        findClosestEnemy();
        findDir();
        moveAI();
    } else {
        if (_safePlaceFound == false)
            findSafePlace();
        else
            goToSafePlace();
    }

    // POUR TESTS :
    // fileManagement.openFile("./Assets/maps/map.txt");
    // for (auto &i: _map)
    //     fileManagement.writeInFile(i + '\n');
}

void ECS::AI::findClosestEnemy()
{
    std::vector<std::pair<int, int>> enemyPositions;

    for (size_t x = 0; x < _map.size(); ++x) {
        for (size_t y = 0; y < _map[x].size(); ++y) {
            if ((_map[x][y] != 'S' && _map[x][y] != 'O' && _map[x][y] != 'X' && _map[x][y] != '#')
            && !((int)x == _x && (int)y == _y))
                enemyPositions.push_back(std::make_pair(x, y));
        }
    }
    int cmpVal = INT_MAX, tmp = 0;
    for (auto &enemyPos: enemyPositions) {
        tmp = std::abs(_x - enemyPos.first) + std::abs(_y - enemyPos.second);
        if (tmp < cmpVal) {
            cmpVal = tmp;
            _closestEnemyPos = std::make_pair(enemyPos.first, enemyPos.second);
        }
    }
}

void ECS::AI::findDir()
{
    if (_x == _closestEnemyPos.first) {
        if (_y < _closestEnemyPos.second)
            _dir = RIGHT;
        else
            _dir = LEFT;
    } else if (_y == _closestEnemyPos.second) {
        if (_x < _closestEnemyPos.first)
            _dir = DOWN;
        else
            _dir = UP;
    } else {
        if (std::abs(_x - _closestEnemyPos.first) < std::abs(_y - _closestEnemyPos.second)) {
            if (_x < _closestEnemyPos.first)
                _dir = DOWN;
            else
                _dir = UP;
        } else {
            if (_y < _closestEnemyPos.second)
                _dir = RIGHT;
            else
                _dir = LEFT;
        }
    }
}

void ECS::AI::moveAI()
{
    if (isInEnemyRange() == true) {
        /* AI pose une bombe ici */
        _isRunningAway = true;
    }
    _map[_x][_y] = 'O';
    if (move(_dir, _map) == false) {
        /* AI pose une bombe ici */
        _isRunningAway = true;
    } else
        graphicMove(_dir);
    _map[_x][_y] = 'Z';
}

void ECS::AI::findSafePlace()
{
    std::vector<std::pair<int, int>> searchDirections;
    std::vector<std::pair<int, int>> lastPositions;
    std::vector<std::pair<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, int>>>> pathLengths_safePos_lastPos;

    searchDirections.push_back(std::make_pair(_x - 1, _y));
    searchDirections.push_back(std::make_pair(_x + 1, _y));
    searchDirections.push_back(std::make_pair(_x, _y - 1));
    searchDirections.push_back(std::make_pair(_x, _y + 1));
    for (auto &safePos: searchDirections) {
        if (_map[safePos.first][safePos.second] == 'S' || _map[safePos.first][safePos.second] == 'O') {
            lastPositions.clear();
            lastPositions.push_back(safePos);
            for (int pathLength = 1; 1; pathLength += 1) {
                if ((_map[safePos.first - 1][safePos.second] == 'S' || _map[safePos.first - 1][safePos.second] == 'O') &&
                isInLastPositions(lastPositions, std::make_pair(safePos.first - 1, safePos.second)) == false &&
                isInBombRange(safePos.first - 1, safePos.second) == false)
                    safePos.first -= 1;
                else if ((_map[safePos.first + 1][safePos.second] == 'S' || _map[safePos.first + 1][safePos.second] == 'O') &&
                isInLastPositions(lastPositions, std::make_pair(safePos.first + 1, safePos.second)) == false &&
                isInBombRange(safePos.first + 1, safePos.second) == false)
                    safePos.first += 1;
                else if ((_map[safePos.first][safePos.second - 1] == 'S' || _map[safePos.first][safePos.second - 1] == 'O') &&
                isInLastPositions(lastPositions, std::make_pair(safePos.first, safePos.second - 1)) == false &&
                isInBombRange(safePos.first, safePos.second - 1) == false)
                    safePos.second -= 1;
                else if ((_map[safePos.first][safePos.second + 1] == 'S' || _map[safePos.first][safePos.second + 1] == 'O') &&
                isInLastPositions(lastPositions, std::make_pair(safePos.first, safePos.second + 1)) == false &&
                isInBombRange(safePos.first, safePos.second + 1) == false)
                    safePos.second += 1;
                else {
                    pathLengths_safePos_lastPos.push_back(std::make_pair(std::make_pair(pathLength, safePos), lastPositions));
                    break;
                }
                lastPositions.push_back(safePos);
            }
        }
    }
    int tmp = INT_MAX;
    for (auto &i: pathLengths_safePos_lastPos) {
        if (i.first.first < tmp) {
            _safePlacePos = i.first.second;
            _pathToSafePlace = i.second;
            tmp = i.first.first;
        }
    }
    _safePlaceFound = true;
}

bool ECS::AI::isInBombRange(int x, int y)
{
    // On compare à _x et _y, car à ce moment-là les coordonnées de la bombe
    // sont les mêmes que celles du joueur
    if (((_x - _bombRange <= x && x <= _x) || (_x <= x && x <= _x + _bombRange)) && y == _y)
        return true;
    if (((_y - _bombRange <= y && y <= _y) || (_y <= y && y <= _y + _bombRange)) && x == _x)
        return true;
    return false;
}

bool ECS::AI::isInLastPositions(std::vector<std::pair<int, int>> vector, std::pair<int, int> pair)
{
    if (std::find(vector.begin(), vector.end(), pair) != vector.end())
        return true;
    else
        return false;
}

void ECS::AI::goToSafePlace()
{
    std::pair<int, int> lastPosition = _pathToSafePlace.front();
    ECS::Direction dir;

    // // _map[_x][_y] = '1';
    // setPosX(lastPosition.first);
    // setPosY(lastPosition.second);
    // // _map[_x][_y] = 'A';

    if (lastPosition.first == _x - 1)
        dir = UP;
    else if (lastPosition.first == _x + 1)
        dir = DOWN;
    else if (lastPosition.second == _y - 1)
        dir = LEFT;
    else if (lastPosition.second == _y + 1)
        dir = RIGHT;
    _map[_x][_y] = 'O';
    move(dir, _map);
    _map[_x][_y] = 'Z';
    graphicMove(dir);

    if (std::make_pair(_x, _y) == _safePlacePos) {
        _isRunningAway = false;
        _safePlaceFound = false;
    }
    _pathToSafePlace.erase(_pathToSafePlace.begin());
}

bool ECS::AI::isInEnemyRange()
{
    if (_closestEnemyPos.first - _bombRange <= _x && _x <= _closestEnemyPos.first && _y == _closestEnemyPos.second) {
        for (int x = _x; x < _closestEnemyPos.first; ++x) {
            if (_map[x][_y] == 'X' || _map[x][_y] == '#')
                return false;
        }
        return true;
    }
    if (_closestEnemyPos.first <= _x && _x <= _closestEnemyPos.first + _bombRange && _y == _closestEnemyPos.second) {
        for (int x = _closestEnemyPos.first; x < _x; ++x) {
            if (_map[x][_y] == 'X' || _map[x][_y] == '#')
                return false;
        }
        return true;
    }
    if (_closestEnemyPos.second - _bombRange <= _y && _y <= _closestEnemyPos.second && _x == _closestEnemyPos.first) {
        for (int y = _y; y < _closestEnemyPos.second; ++y) {
            if (_map[_x][y] == 'X' || _map[_x][y] == '#')
                return false;
        }
        return true;
    }
    if (_closestEnemyPos.second <= _y && _y <= _closestEnemyPos.second + _bombRange && _x == _closestEnemyPos.first) {
        for (int y = _closestEnemyPos.second; y < _y; ++y) {
            if (_map[_x][y] == 'X' || _map[_x][y] == '#')
                return false;
        }
        return true;

    }
    return false;
}

// Pour les tests : boucle de jeu avec usleep() (0.5 sec) :
// -> Appeller la méthode runAI() une fois par tour de boucle de jeu pour chaque AI

/* int main(int ac, char **av)
{
    ECS::AI ai;

    while (1) {
        usleep(500000);
        ai.runAI();
    }
    return 0;
} */