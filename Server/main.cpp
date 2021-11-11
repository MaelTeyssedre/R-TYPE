/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** main
*/

#include <iostream>
#include "JsonWrapper.hpp"

int main()
{
    JsonWrapper wrapper("test.json");
    std::string result;

    wrapper.fillComposantList();
    return (0);
}