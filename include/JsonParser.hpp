/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** JsonParser
*/

#ifndef JSONPARSER_HPP_
#define JSONPARSER_HPP_

#include "Serializer.hpp"
#include "Deserializer.hpp"
#include <memory>

class JsonParser {
    public:
        JsonParser();
        ~JsonParser();
        Serializer *serializer;
        Deserializer *deserializer;

    protected:
    private:
};

#endif /* !JSONPARSER_HPP_ */
