/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** IChrono
*/

#pragma once

#include "iostream"
#include "chrono"

class IChrono {
    public:
        IChrono(){};
        virtual ~IChrono(){};

        virtual void resetChrono() = 0;
        virtual void startChrono() = 0;
        virtual double getElapsedTime() = 0;
};
