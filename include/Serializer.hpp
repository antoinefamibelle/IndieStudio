/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Serializer
*/

#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include "Object.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class Serializer {
    public:
        Serializer();
        ~Serializer();
        void serialize(std::vector<ECS::Object *> objects);

    protected:
    private:
        std::string toJson(std::string name, std::string value) const;
        void setupJsonFile();
        void closeJsonFile();

        void openFile(std::string file);
        void writeInFile(std::string text);
        void closeFile();

        std::ofstream _file;
};

#endif /* !SERIALIZER_HPP_ */
