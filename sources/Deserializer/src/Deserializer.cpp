/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Deserializer
*/

#include "Deserializer.hpp"

Deserializer::Deserializer()
{
}

Deserializer::~Deserializer()
{
}

std::size_t Deserializer::findWordPos(std::string line, std::string nb)
{
    std::size_t first = line.find("\"");

    if (nb == "first")
        return first;
    first = line.find("\"", first + 1);
    return line.find("\"", first + 1);
}

std::string Deserializer::extractWord(std::string line, std::string nb)
{
    std::size_t first = findWordPos(line, nb);
    std::size_t second = line.find("\"", first + 1);

    if (first == std::string::npos || second == std::string::npos)
        return "";
    return line.substr(first + 1, second - first - 1);
}

void Deserializer::addToClass(std::string line)
{
    std::string first = this->extractWord(line, "first");
    std::string second = this->extractWord(line, "second");
    
    if (first.empty() || second.empty())
        return ;
    if (first == "_objectType")
        this->_tmp->setType((ECS::ObjectType)std::stoi(second));
    if (first == "_id")
        this->_tmp->setId(std::stoi(second));
    if (first == "_x")
        this->_tmp->setPosX(std::stoi(second));
    if (first == "_y")
        this->_tmp->setPosY(std::stoi(second));
    if (first == "_isEmpty")
        this->_tmp->setEmpty(std::stoi(second));
}

std::vector<ECS::Object *> Deserializer::deserialize(std::string file)
{
    std::vector<ECS::Object *> objects;
    this->_tmp = new ECS::Object();
    std::vector<std::string> content = this->readFile(file);
    int counter = 0;

    for (auto &i: content) {
        if (i.find("},") != std::string::npos) {
            objects.push_back(_tmp);
            this->_tmp = new ECS::Object();
        } else if (i.find("}") != std::string::npos) {
            if (counter == 0)
                objects.push_back(_tmp);
            counter++;
        } else
            this->addToClass(i);
    }
    return objects;
}