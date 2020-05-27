/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Serializer
*/

#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include "Object.hpp"
#include "FileManagement.hpp"

class Serializer : public FileManagement {
    public:
        Serializer();
        ~Serializer();
        void serialize(std::vector<ECS::Object *> objects);

    protected:
    private:
        std::string toJson(std::string name, std::string value) const;
        void setupJsonFile();
        void closeJsonFile();
};

#endif /* !SERIALIZER_HPP_ */
