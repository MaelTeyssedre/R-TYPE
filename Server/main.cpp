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

    std::cout << wrapper.jsonToString() << std::endl;
    result = wrapper.getJsonValue(std::string("monster"), std::string("6"), std::string("pos"));
    std::cout << result << std::endl;
    wrapper.createJsonFromString(wrapper.jsonToString());
    return (0);
}