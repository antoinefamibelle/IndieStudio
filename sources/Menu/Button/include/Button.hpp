/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "MyIrrlicht.hpp"
#include "StaticEntity.hpp"


class Button : public ECS::StaticEntity {
    public:
        Button(std::string name, int x, int y, int sizeX, int sizeY, ITexture *texture, ITexture *Pressed)
        {
            this->_name = name;
            this->_isSelected = false;
            this->_sizeX = sizeX;
            this->_sizeY = sizeY;
            this->setPosX(x);
            this->setPosY(y);
            this->_IrrlichtButton = texture;
            this->_IrrlichtButtonPressed = Pressed;
        };
        ~Button() {};

        std::string getName() const { return this->_name; };
        ITexture *getButton() const { return this->_isSelected == false ? this->_IrrlichtButton : this->_IrrlichtButtonPressed; };
        void setIsSelected(bool isSelected) { this->_isSelected = isSelected; };
        bool getIsSelected() const { return this->_isSelected; };
        int getX() { return this->getPosX(); };
        int getY() { return this->getPosY(); };
        int getSizeX() { return this->_sizeX; };
        int getSizeY() { return this->_sizeY; };
    protected:
    private:
        int _sizeX;
        int _sizeY;
        std::string _name;
        bool _isSelected;
        ITexture *_IrrlichtButton;
        ITexture *_IrrlichtButtonPressed;
};

#endif /* !BUTTON_HPP_ */
