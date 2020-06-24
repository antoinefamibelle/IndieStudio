/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Menu
*/

#include "Menu.hpp"

IMenu::IMenu(ITexture* background, std::vector<std::pair<Button, bool>> buttons) : _index(0), _background(background), _buttons(buttons)
{
}

IMenu::~IMenu()
{
}

void IMenu::changeButtonState(int index, bool isSpecial)
{
    if (isSpecial == false)
        this->changeNormalButtonState(index);
    else
        this->changeSpecialButtonState(index);
}

void IMenu::changeNormalButtonState(int index)
{
    if (this->_index + index < 0 || this->_index + index > this->_buttons.size() - 1)
        return;
    this->_buttons.at(this->_index).first.setIsSelected(false);
    this->_buttons.at(this->_index).second = false;
    this->_index += index;
    this->_buttons.at(this->_index).first.setIsSelected(true);
    this->_buttons.at(this->_index).second = true;
}

void IMenu::changeSpecialButtonState(int index)
{
    if ((this->_index - 1 < 0 && index == -3 ) || (this->_index + 1 > this->_buttons.size() - 1 && index == 3))
        return;
    this->_buttons.at(this->_index).first.setIsSelected(false);
    this->_buttons.at(this->_index).second = false;
    this->_index+= index == -3 ? -1 : 1;
    this->_buttons.at(this->_index).first.setIsSelected(true);
    this->_buttons.at(this->_index).second = true;
}

Button IMenu::getButtonAction() const
{
    return this->_buttons.at(this->_index).first; 
}