/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** ManageMenu
*/

#include "ManageMenu.hpp"

ManageMenu::ManageMenu()
{
    this->_irrlicht = new MyIrrlicht();
    this->_irrlicht->initWindow(1080, 720);
    std::vector<std::string> name = {"SOLO", "MULTIPLAYER", "EXIT"};
    std::vector<std::pair<ITexture *, ITexture *>> buttons;
    buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_solo.png"), this->_irrlicht->loadImage("./Assets/images/pressed_solo.png")));
    buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_multiplayer.png"), this->_irrlicht->loadImage("./Assets/images/pressed_multiplayer.png")));
    buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_exit.png"), this->_irrlicht->loadImage("./Assets/images/pressed_exit.png")));
    std::vector<std::string> _name = {"READY", "BACK"};
    std::vector<std::pair<ITexture *, ITexture *>> _buttons;
    _buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_ready.png"), this->_irrlicht->loadImage("./Assets/images/pressed_ready.png")));
    _buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_back.png"), this->_irrlicht->loadImage("./Assets/images/pressed_back.png")));
    this->startMenu = new Menu(this->_irrlicht->loadImage("./Assets/images/background.png"), this->createVector(name, 360, 80, 467, 117, buttons, false));
    this->soloMenu = new Menu(this->_irrlicht->loadImage("./Assets/images/background.png"), this->createVector(_name, 360, 220, 467, 117, _buttons, false));

    std::vector<std::string> __name = {"1", "2", "3", "4"};
    std::vector<std::pair<ITexture *, ITexture *>> __buttons;
    __buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_1player.png"), this->_irrlicht->loadImage("./Assets/images/notpressed_1player.png")));
    __buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_2player.png"), this->_irrlicht->loadImage("./Assets/images/notpressed_2player.png")));
    __buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_3player.png"), this->_irrlicht->loadImage("./Assets/images/notpressed_3player.png")));
    __buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_4player.png"), this->_irrlicht->loadImage("./Assets/images/notpressed_4player.png")));
    this->multiplayerMenu = new Menu(this->_irrlicht->loadImage("./Assets/images/background.png"), this->createVector(__name, 360, 520, 467, 117, __buttons, true), true);
    this->multiplayerMenu->setSpecialImg(this->_irrlicht->loadImage("./Assets/images/plyhead.png"));
    this->_sound = new Sound();
    this->_sound->menuMusic();
}

ManageMenu::~ManageMenu()
{
}

std::vector<std::pair<Button, bool>> ManageMenu::createVector(std::vector<std::string> name, int x, int y, int sizeX, int sizeY, std::vector<std::pair<ITexture *, ITexture *>> buttons, bool isSpecial)
{
    std::vector<std::pair<Button, bool>> ret;
    int j = 1;

    Button tmp = Button(name.at(0), x, y, sizeX, sizeY, buttons.at(0).first, buttons.at(0).second);
    tmp.setIsSelected(true);
    ret.push_back(std::make_pair(tmp, true));
    name.erase(name.begin());

    for (auto &i: name) {
        y += isSpecial == false ? 150 : 0;
        tmp = Button(i, x, y, sizeX, sizeY, buttons.at(j).first, buttons.at(j).second);
        ret.push_back(std::make_pair(tmp, false));
        j++;
    }
    return ret;
}

std::string ManageMenu::manageMenu(Menu *menu)
{
    //irrlichtfunction to have input returns 1 or -1 or 2
    int i = this->_irrlicht->getMenuInput();

    if (i == 84)
        return "";
    if (i == 2)
        return menu->getButtonAction().getName();
    else
        menu->changeButtonState(i, menu->getIsSpecial());
    return "";
}

void ManageMenu::displayMenu(Menu *menu)
{
    this->_irrlicht->startScene();
    this->_irrlicht->draw(menu->getBackground(), 0, 0, 1080, 720);
    for (auto &i: menu->getButtons()) {
        if (menu->getIsSpecial() == false)
            this->_irrlicht->draw(i.first.getButton(), i.first.getX(), i.first.getY(), i.first.getSizeX(), i.first.getSizeY());
        if (menu->getIsSpecial() == true && i.first.getIsSelected() == true)
            this->_irrlicht->draw(i.first.getButton(), i.first.getX(), i.first.getY(), i.first.getSizeX(), i.first.getSizeY());
    }
    if (menu->getIsSpecial() == true)
        this->_irrlicht->draw(menu->getSpecialImg(), 360, 100, 465, 400);
    this->_irrlicht->endScene();
}

// Fonction a finir : SI solo ?? Si multi ??

std::string ManageMenu::MenuProcess()
{
    int whichMenu = 0;
    std::string ret;
    int _ret = -1;

    while (this->_irrlicht->isWindowOpen()) {
        if (whichMenu == 0) {
            if ((ret = this->manageMenu(this->startMenu)) == "SOLO")
                whichMenu = 1;
            else if (ret == "MULTIPLAYER")
                whichMenu = 2;
            else if (ret == "EXIT") {
                this->_irrlicht->_device->drop();
                return "EXIT";
            }
            this->displayMenu(this->startMenu);
        }
        if (whichMenu == 1) {
            if ((ret = this->manageMenu(this->soloMenu)) == "BACK")
                whichMenu = 0;
            if (ret == "READY") {
                this->_irrlicht->_device->drop();
                return "SOLO";
            }
            this->displayMenu(this->soloMenu);
        }
        if (whichMenu == 2) {
            if ((ret = this->manageMenu(this->multiplayerMenu)) != "") {
                this->_irrlicht->_device->drop();
                return ret;
            }
            this->displayMenu(this->multiplayerMenu);
        }
    }
    return "";
}

std::string ManageMenu::EndMenuProcess(int index)
{
    // this->_irrlicht = new MyIrrlicht();
    std::string ret;
    std::vector<std::string> name = {"PLAYAGAIN", "GOTOMENU", "EXIT"};
    std::vector<std::pair<ITexture *, ITexture *>> buttons;
    buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_playagain.png"), this->_irrlicht->loadImage("./Assets/images/pressed_playagain.png")));
    buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_gotomenu.png"), this->_irrlicht->loadImage("./Assets/images/pressed_gotomenu.png")));
    buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_exit.png"), this->_irrlicht->loadImage("./Assets/images/pressed_exit.png")));
    
    this->endMenu = new Menu(this->_irrlicht->loadImage("./Assets/images/background.png"), this->createVector(name, 360, 250, 467, 117, buttons, false));
    this->endMenu->setSpecialImg(this->_irrlicht->loadImage("./Assets/images/ply" + std::to_string(index + 1) + "_win.png"));
    
    while (this->_irrlicht->isWindowOpen()) {
        if ((ret = this->manageMenu(this->endMenu)) == "EXIT")
            return "EXIT";
        else if (ret == "GOTOMENU")
            return "EXIT";
        else if (ret == "PLAYAGAIN")
            return "EXIT";
        this->_irrlicht->startScene();
        this->_irrlicht->draw(this->endMenu->getBackground(), 0, 0, 1080, 720);
        for (auto &i: this->endMenu->getButtons())
            this->_irrlicht->draw(i.first.getButton(), i.first.getX(), i.first.getY(), i.first.getSizeX(), i.first.getSizeY());
        this->_irrlicht->draw(this->endMenu->getSpecialImg(), 360, 100, 467, 117);
        this->_irrlicht->endScene();
    }
    return ""; 
}

std::string ManageMenu::PauseMenuProcess()
{
    // this->_irrlicht = new MyIrrlicht();
    std::string ret;
    std::vector<std::string> name = {"RESUME", "SAVEANDQUIT"};
    std::vector<std::pair<ITexture *, ITexture *>> buttons;
    buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_resume.png"), this->_irrlicht->loadImage("./Assets/images/pressed_resume.png")));
    buttons.push_back(std::make_pair(this->_irrlicht->loadImage("./Assets/images/notpressed_saveandquit.png"), this->_irrlicht->loadImage("./Assets/images/pressed_saveandquit.png")));
    
    this->pauseMenu = new Menu(this->_irrlicht->loadImage("./Assets/images/background.png"), this->createVector(name, 360, 250, 467, 117, buttons, false));
    // this->pauseMenu->setSpecialImg(this->_irrlicht->loadImage("./Assets/images/btn/solo.png"));
    
    while (this->_irrlicht->isWindowOpen()) {
        if ((ret = this->manageMenu(this->pauseMenu)) == "SAVEANDQUIT") {
            this->_irrlicht->_device->drop();
            return "EXIT";
        } else if (ret == "RESUME") {
            this->_irrlicht->_device->drop();
            return "RESUME";
        }
        this->_irrlicht->startScene();
        this->_irrlicht->draw(this->pauseMenu->getBackground(), 0, 0, 1080, 720);
        for (auto &i: this->pauseMenu->getButtons())
            this->_irrlicht->draw(i.first.getButton(), i.first.getX(), i.first.getY(), i.first.getSizeX(), i.first.getSizeY());
        // this->_irrlicht->draw(this->pauseMenu->getSpecialImg(), 360, 100, 467, 117);
        this->_irrlicht->endScene();
    }
    return ""; 
}

// void ManageMenu::DisplayMap()
// {
//     this->_TMap = new TMap(this->_irrlicht->getDevice());

//     while (this->_irrlicht->isWindowOpen()) {
//         this->_irrlicht->getDriver()->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
//         this->_irrlicht->getScene()->drawAll();
//         this->_irrlicht->getEnv()->drawAll();
//         this->_irrlicht->getDriver()->endScene();
//     }
// }

int ManageMenu::head()
{
    
    std::string tmp = this->MenuProcess();

    if (tmp == "SOLO")
        return 5;
    if (tmp == "EXIT")
        return -1;
    if (tmp != "")
        return std::stoi(tmp); 
    return 0;
}