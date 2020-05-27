/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** FileManagement
*/

#include "FileManagement.hpp"

FileManagement::FileManagement()
{
}

FileManagement::~FileManagement()
{
}

void FileManagement::openFile(std::string file)
{
    this->_ofile.open(file);
    if (!this->_ofile.is_open())
        throw "Unable to open file: " + file + "\n";
}

void FileManagement::writeInFile(std::string text)
{
    this->_ofile << text;
}

void FileManagement::closeFile()
{ 
    this->_ofile.close();
}

std::vector<std::string> FileManagement::readFile(std::string file)
{
    std::vector<std::string> readedFile;
    std::string tmp;
    std::ifstream _ifile(file);

    if (!_ifile.is_open())
        throw "Unable to open file: " + file + "\n";
    while (std::getline(_ifile, tmp))
        readedFile.push_back(tmp);
    _ifile.close();
    return readedFile;
}