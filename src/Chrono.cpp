/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Chrono
*/

#include "Chrono.hpp"

Chrono::Chrono()
{
}

Chrono::~Chrono()
{
}

std::string Chrono::getTime()
{
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    return std::ctime(&end_time);
}

void Chrono::resetChrono()
{
    this->startChrono();
}

void Chrono::startChrono()
{
    this->_begin = std::chrono::system_clock::now();
}

double Chrono::getElapsedTime()
{
    this->_end = std::chrono::system_clock::now();
    std::chrono::duration<double> result = this->_end - this->_begin;
    return result.count();
}