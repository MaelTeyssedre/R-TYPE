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
    std::vector<std::vector<JsonWrapper::composant_s>> composantList;

    wrapper.fillComposantList();
    composantList = wrapper.getComposantList();
    for (auto &it: composantList) {
        for (auto &it2: it) {
            std::cout << "Type: " << it2.type << " id: " << it2.id << " Pos: " << it2.pos.first << ", " << it2.pos.second << " Strength: " << it2.strength << " hp: " << it2.hp << " loot: " << it2.loot << std::endl; 
        }
    }
    return (0);
}