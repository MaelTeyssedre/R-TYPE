/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** DlLoaderWindows
*/

#include "DlLoaderWindows.hpp"

// ? Rajouter des throw?
HMODULE DlLoaderWindows::loadLib(std::string path)
{
    std::wstring sw = std::wstring(path.begin(), path.end());
    //LPCWSTR sw = stemp.c_str();
    //std::wstring widestr = std::wstring(path.begin(), path.end());
    //LPCWSTR csw = sw.c_str();
    //CStringA strA(path.c_str());
    return (_hDLL = LoadLibrary(path.c_str()));
}

HANDLE DlLoaderWindows::loadFunc(std::string &function, HMODULE hDLL)
{
    return (_Proc = GetProcAddress(hDLL, function.c_str()));
}

void DlLoaderWindows::closeLib(HMODULE hDLL)
{
    FreeLibrary(hDLL);
}