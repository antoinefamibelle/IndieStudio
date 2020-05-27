/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Serializer
*/

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

void Serializer::openFile(std::string file)
{
    this->_file.open(file);
}

void Serializer::writeInFile(std::string text)
{
    this->_file << text;
}

void Serializer::closeFile()
{
    this->_file.close();
}

std::string Serializer::toJson(std::string name, std::string value) const
{
    return "\"" + name + "\"" + ":" + " \"" + value + "\"";
}

void Serializer::setupJsonFile()
{
    this->openFile("./conf/data.conf");
    this->writeInFile("{\n");
}

void Serializer::closeJsonFile()
{
    this->writeInFile("}\n");
    this->closeFile();
}

void Serializer::serialize(std::vector<ECS::Object *> objects)
{
    this->setupJsonFile();
    for (auto &i: objects) {
        writeInFile("\t\"object\": {\n");
        writeInFile("\t\t" + toJson("_objectType", std::to_string(i->getType())) + ",\n");
        writeInFile("\t\t" + toJson("_id", std::to_string(i->getId())) + ",\n");
        writeInFile("\t\t" + toJson("_x", std::to_string(i->getPosX())) + ",\n");
        writeInFile("\t\t" + toJson("_y", std::to_string(i->getPosY())) + ",\n");
        writeInFile("\t\t" + toJson("_isEmpty", std::to_string(i->isEmpty())) + "\n");
        writeInFile("\t},\n");
    }
    this->closeJsonFile();
}