#!/bin/bash

check_if_CMakeLisk_exists() {
    echo -e "    \e[33m-> Check: CMake exists. <-"
    if [ -e CMakeLists.txt ]; then
        echo -e "\e[32m-- CMakeLists.txt: found."
    else
        echo -e "\e[31m-- CMakeLists.txt: not found."
    fi
}

check_if_windows_directories() {
    echo -e ""
    echo -e "    \e[33m-> Check: Windows directories. <-"
    if [ -d Release ]; then
        echo -e "\e[32m-- Release directory for Windows exists."
    else
        echo -e "\e[31m-- Release directory for Windows not found."
    fi
    if [ -d Debug ]; then
        echo -e "\e[32m-- Debug directory for Windows exist."
    else
        echo -e "\e[31m-- Debug directory for Windows not found."
    fi
}

check_if_windows_directories_content() {
    echo -e ""
    echo -e "    \e[33m-> Check: Windows directories content. <-"
    if [ -e Release/Irrlicht.dll ]; then
        echo -e "\e[32m-- Release: Irrlicht.dll found."
    else
        echo -e "\e[31m-- Release: Irrlicht.dll not found."
    fi
    if [ -e Debug/Irrlicht.dll ]; then
        echo -e "\e[32m-- Debug: Irrlicht.dll found."
    else
        echo -e "\e[31m-- Debug: Irrlicht.dll not found."
    fi
}

remove_windows_debug() {
    find . -type f -name '*.ilk' -delete
    find . -type f -name '*.pdb' -delete
}

remove_windows_executable() {
    find . -type f -name '*.exe' -delete
}

remove_linux_binary() {
    find . -type f -name 'indie_studio' -delete
}

remove_build_directory() {
    if [ -d build ]; then
        rm -rf build
    fi
}

regenerate_build_directory() {
    mkdir build
    echo -e ""
    echo -e "\e[33m    -> Everything regenerated. <-"
    echo -e ""
}

check_if_CMakeLisk_exists
check_if_windows_directories
check_if_windows_directories_content
remove_windows_debug
remove_windows_executable
remove_linux_binary
remove_build_directory
regenerate_build_directory