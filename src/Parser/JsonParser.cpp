/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** JsonParser
*/

#include "JsonParser.hpp"

JsonParser::JsonParser()
{
    this->serializer = new Serializer();
    this->deserializer = new Deserializer();
}

JsonParser::~JsonParser()
{
}
