/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** IFileManagement
*/

#ifndef FILEMANAGEMENT_HPP_
#define FILEMANAGEMENT_HPP_

#include <iostream>
#include <fstream>
#include <vector>

class FileManagement {
    public:
        FileManagement();
        ~FileManagement();
        void openFile(std::string file);
        void writeInFile(std::string text);
        void closeFile();
        std::vector<std::string> readFile(std::string file);

    protected:
    private:
        std::ofstream _ofile;
};

#endif /* !FILEMANAGEMENT_HPP_ */
