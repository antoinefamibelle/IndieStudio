/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_


#include "Button.hpp"
#include <vector>

class IMenu {
    public:
        IMenu(ITexture* background, std::vector<std::pair<Button, bool>> buttons);
        ~IMenu();
        
        void changeButtonState(int index, bool isSpecial);
        void changeNormalButtonState(int index);
        void changeSpecialButtonState(int index);
        Button getButtonAction() const;
        ITexture *getBackground() const { return this->_background; };
        std::vector<std::pair<Button, bool>> getButtons() { return this->_buttons; };

    protected:
    private:
        std::vector<std::pair<Button, bool>> _buttons;
        ITexture *_background;
        int _index;
};

class Menu : public IMenu {
    public:
        Menu(ITexture* background, std::vector<std::pair<Button, bool>> buttons) : IMenu(background, buttons) {
            this->_isSpecial = false;
        };
        Menu(ITexture* background, std::vector<std::pair<Button, bool>> buttons, bool isSpecial) : IMenu(background, buttons) {
            this->_isSpecial = isSpecial;
        };
        // Menu() {};
        ~Menu() {};
        bool getIsSpecial() const { return this->_isSpecial; };
        void setSpecialImg(ITexture *texture) { this->_specialImg = texture; };
        ITexture *getSpecialImg() const { return this->_specialImg; };
    protected:
    private:
        ITexture *_specialImg;
        bool _isSpecial;
};

#endif /* !MENU_HPP_ */
