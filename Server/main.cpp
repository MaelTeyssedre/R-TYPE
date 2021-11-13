/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** main
*/

#include <iostream>
//#include <asio.hpp>
#include "LibLoader.hpp"
#include "windows.h"


int main()
{
    std::cout << "Server" << std::endl;
    LibLoader lib = LibLoader();

    ///GetProcAddress(LoadLibrary("BasicMonster.dll"), "allocator")();

    //lib.getLibs();
    return (0);
}
