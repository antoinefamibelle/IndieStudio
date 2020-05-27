/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Deserializer
*/

#ifndef DESERIALIZER_HPP_
#define DESERIALIZER_HPP_

#include "FileManagement.hpp"
#include "Object.hpp"
#include <cstddef>
class Deserializer : FileManagement {
    public:
        Deserializer();
        ~Deserializer();
        std::vector<ECS::Object *> deserialize(std::string file);

    protected:
    private:
        std::string extractWord(std::string line, std::string nb);
        std::size_t findWordPos(std::string line, std::string nb);
        void addToClass(std::string line);
    
        ECS::Object *_tmp;
};

#endif /* !DESERIALIZER_HPP_ */
