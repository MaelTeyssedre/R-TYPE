/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** DlLoaderWindows
*/

#include "DlLoaderWindows.hpp"

HMODULE DlLoaderWindows::loadLib(std::string path)
{
    return (LoadLibrary(path.c_str()));
}

allocClass DlLoaderWindows::loadFunc(std::string &function, HMODULE hDLL)
{
    return ((allocClass)GetProcAddress(hDLL, function.c_str()));
}

void DlLoaderWindows::closeLib(HMODULE hDLL)
{
    FreeLibrary(hDLL);
}