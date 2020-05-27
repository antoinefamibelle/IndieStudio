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
    for (std::vector<ECS::Object *>::iterator it = objects.begin(); it != objects.end(); ++it) {
        writeInFile("\t\"object\": {\n");
        writeInFile("\t\t" + toJson("_objectType", std::to_string((*it)->getType())) + ",\n");
        writeInFile("\t\t" + toJson("_id", std::to_string((*it)->getId())) + ",\n");
        writeInFile("\t\t" + toJson("_x", std::to_string((*it)->getPosX())) + ",\n");
        writeInFile("\t\t" + toJson("_y", std::to_string((*it)->getPosY())) + ",\n");
        writeInFile("\t\t" + toJson("_isEmpty", std::to_string((*it)->isEmpty())) + "\n");
        if (std::next(it) == objects.end())
            writeInFile("\t}\n");
        else
            writeInFile("\t},\n");
    }
    this->closeJsonFile();
}