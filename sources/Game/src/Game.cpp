/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Game
*/

#include "Game.hpp"

Indie::Game::Game()
{
    this->_File = new FileManagement();
    this->_sound = new Sound();
}

Indie::Game::~Game()
{
}

void Indie::Game::printMapInfo()
{
    for (auto &i : this->_TextMap)
        std::cout << i << std::endl;
}

void Indie::Game::movePlayer(int dir, ECS::Character *player)
{
    if (dir == -1 && player->move(ECS::Direction::UP, this->_TextMap) == true) {
        this->_TextMap[player->getPosX() + 1][player->getPosY()] = 'O';
        this->_TextMap[player->getPosX()][player->getPosY()] = 'Z';
        player->graphicMove(ECS::Direction::UP);
    }
    if (dir == 1 && player->move(ECS::Direction::DOWN, this->_TextMap) == true) {
        this->_TextMap[player->getPosX() - 1][player->getPosY()] = 'O';
        this->_TextMap[player->getPosX()][player->getPosY()] = 'Z';
        player->graphicMove(ECS::Direction::DOWN);
    }
    if (dir == -2 && player->move(ECS::Direction::LEFT, this->_TextMap) == true) {
        this->_TextMap[player->getPosX()][player->getPosY() + 1] = 'O';
        this->_TextMap[player->getPosX()][player->getPosY()] = 'Z';
        player->graphicMove(ECS::Direction::LEFT);
    }
    if (dir == 2 && player->move(ECS::Direction::RIGHT, this->_TextMap) == true) {
        this->_TextMap[player->getPosX()][player->getPosY() - 1] = 'O';
        this->_TextMap[player->getPosX()][player->getPosY()] = 'Z';
        player->graphicMove(ECS::Direction::RIGHT);
    }
    if (dir == 3)
        player->getBomb()->pose(player->getPosX(), player->getPosY());
}

void Indie::Game::isTicking()
{
    for (auto &i : this->_players) {
        if (i->isTicking() == true) {
            i->explose(this->_TextMap, this->_players);
        }
    }
}

int Indie::Game::pause()
{
    std::string ret;

    this->_manageMenu = new ManageMenu();
    if ((ret = this->_manageMenu->PauseMenuProcess()) == "EXIT") {
        this->_File->openFile("./Assets/maps/savemap.txt");
        for (auto &i: this->_TextMap)
            this->_File->writeInFile(i + '\n');
        this->_File->closeFile();
        this->_File->openFile("./Assets/maps/playerpos.txt");
        for (auto &i: this->_players)
            this->_File->writeInFile("PlayerID: " + std::to_string(i->getId()) + " playerX: " + std::to_string(i->getPosX()) + " playerY: " + std::to_string(i->getPosY()) + "\n");
        this->_File->closeFile();
        return -1;
    }
    return 0;
}

void Indie::Game::play(int nbplayer, bool isSolo)
{
    bool isStarted = true;
    this->_MyIrrlicht = new MyIrrlicht();
    this->_MyIrrlicht->initWindow(1920, 1080);
    // SPLASH SCREEN
    ITexture *splashscreen = this->_MyIrrlicht->loadImage("./Assets/images/splashscreen.png");
    while (this->_MyIrrlicht->isWindowOpen()) {
        usleep(100000);
        if (this->_MyIrrlicht->_receiver.IsKeyDown(KEY_SPACE))
            break;
        this->_MyIrrlicht->startScene();
        this->_MyIrrlicht->draw(splashscreen, 0, 0, 1920, 1080);
        this->_MyIrrlicht->endScene();
    }
    this->_chrono = Chrono();
    this->_chrono.startChrono();
    this->_map = this->_MyIrrlicht->createMap();
    if (nbplayer >= 1)
        this->_players.push_back(new ECS::Character(0, 0, 0, _MyIrrlicht->getDevice(), _MyIrrlicht->getScene()));
    if (nbplayer >= 2)
        this->_players.push_back(new ECS::Character(0, 12, 1, _MyIrrlicht->getDevice(), _MyIrrlicht->getScene()));
    if (nbplayer >= 3)
        this->_players.push_back(new ECS::Character(10, 0, 2, _MyIrrlicht->getDevice(), _MyIrrlicht->getScene()));
    if (nbplayer == 4)
        this->_players.push_back(new ECS::Character(10, 12, 3, _MyIrrlicht->getDevice(), _MyIrrlicht->getScene()));
    this->_TextMap = this->_File->readFile("./Assets/maps/map.txt");
    this->_TMap = new TMap(this->_MyIrrlicht->getDevice());

    this->_TextMap = _TMap->createWallArray(this->_TextMap);
    std::reverse(_TextMap.begin(), _TextMap.end());

    this->_sound->gameMusic();
    //this->_Joueur = this->createPlayer(this->_MyIrrlicht);
    for (int dir = 0; this->_MyIrrlicht->isWindowOpen();) {
        usleep(100000);
        if (this->_MyIrrlicht->_receiver.IsKeyDown(KEY_ESCAPE)) {
            if (this->pause() == -1) {
                this->_MyIrrlicht->_device->drop();
                break; 
            }
        }
        for (auto &player : this->_players) {
            if ((dir = this->_MyIrrlicht->getPlayersInput(this->_map.at(player->getId()))) != 0 && isStarted == false) {
                this->movePlayer(dir, player);
                dir = 0;
                // printMapInfo();
            } else
                player->graphicStand();
        }
        if (this->isEnGame() != -1 && isSolo == false) {
            // this->_MyIrrlicht->_device->drop();
            this->_manageMenu = new ManageMenu();
            if (this->_manageMenu->EndMenuProcess(this->isEnGame()) == "EXIT")
                break;
        }
        if (isStarted == true) {
            int i = 3;
            ITexture *tmp;
            if (this->_chrono.getElapsedTime() < 1)
                tmp = this->_MyIrrlicht->loadImage("./Assets/images/3.png");
            if (this->_chrono.getElapsedTime() > 1 && this->_chrono.getElapsedTime() < 2)
                tmp = this->_MyIrrlicht->loadImage("./Assets/images/2.png");
            if (this->_chrono.getElapsedTime() > 2 && this->_chrono.getElapsedTime() < 3)
                tmp = this->_MyIrrlicht->loadImage("./Assets/images/1.png");
            if (this->_chrono.getElapsedTime() > 3)
                isStarted = false;
            this->_MyIrrlicht->getDriver()->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
            this->_MyIrrlicht->getScene()->drawAll();
            this->_MyIrrlicht->getEnv()->drawAll();
            this->_MyIrrlicht->draw(tmp, 1000, 500, 65, 70);
            this->_MyIrrlicht->getDriver()->endScene();
        } else {
            this->_MyIrrlicht->getDriver()->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
            this->_MyIrrlicht->getScene()->drawAll();
            this->_MyIrrlicht->getEnv()->drawAll();
            this->_MyIrrlicht->getDriver()->endScene();
        }
    }
}

int Indie::Game::isEnGame()
{
    int idStock = -1;

    for (auto &i : this->_players) {
        if (i->isAlive() == true && idStock != -1)
            return -1;
        if (i->isAlive() == true && idStock == -1)
            idStock = i->getId();
    }
    return idStock;
}