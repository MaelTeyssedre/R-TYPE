/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** JsonWrapper
*/

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "JsonWrapper.hpp"


JsonWrapper::JsonWrapper(std::string filename)
{
    _filename = filename;
    std::ifstream ifs(_filename);
    _json = nlohmann::json::parse(ifs);
}

JsonWrapper::~JsonWrapper()
{
}

std::string JsonWrapper::jsonToString()
{
    return (_json.dump(4));
}

std::string JsonWrapper::getJsonValue(std::string &composantType, std::string &id, std::string &element)
{
    for (const auto &it: _json[composantType].items()) {
        if (std::stoi(id) == it.value()["id"].get<int>()) {
            if (element.find("type") != std::string::npos) {
                return (it.value()[element].get<std::string>());
            }else {
                std::cout << it.value()[element] << std::endl;
                return (std::to_string(it.value()[element].get<int>()));
            }
        }
    }
    return ("not found");
}

bool JsonWrapper::isNewElementType(std::vector<std::vector<composant_s>> _composantList, std::string type)
{
    for (auto &composant : _composantList) {
        if (type == composant.front().type)
            return (false);
    }
    return (true);
}

JsonWrapper::composant_s JsonWrapper::createComposant(int id, std::pair<int, int> pos, int strength, int hp, bool loot, std::string &type)
{
    JsonWrapper::composant_s element;

    element.id = id;
    element.pos = pos;
    element.strength = strength;
    element.hp = hp;
    element.loot = loot;
    element.type = type;
    return (element);
}

void JsonWrapper::addPlayer()
{
    std::vector<composant_s> playerList;

    for (const auto &it: _json["player"].items()) {
        playerList.push_back(createComposant(it.value()["id"].get<int>(), std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["strength"].get<int>(), it.value()["hp"].get<int>(), false, std::string("player")));
    }
    _composantList.push_back(playerList);
}

void JsonWrapper::addMonster()
{
    std::vector<std::vector<composant_s>> monsterList;
    std::vector<composant_s> element;

    for (const auto &it: _json["monster"].items()) {
        if (monsterList.size() == 0 || isNewElementType(monsterList, it.value()["type"].get<std::string>()) == true) {
            monsterList.push_back(std::vector<composant_s>());
            monsterList.back().push_back(createComposant(it.value()["id"].get<int>(), std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["strength"].get<int>(), it.value()["hp"].get<int>(), it.value()["loot"].get<bool>(), it.value()["type"].get<std::string>())); 
        } else {
            for (auto &monster: monsterList) {
                if (it.value()["type"].get<std::string>() == monster.front().type)
                    monster.push_back(createComposant(it.value()["id"].get<int>(),  std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["strength"].get<int>(), it.value()["hp"].get<int>(), it.value()["loot"].get<bool>(), it.value()["type"].get<std::string>())); 
            }
        }
    }
    _composantList.insert(_composantList.end(), monsterList.begin(), monsterList.end());
}

void JsonWrapper::addWall()
{
    std::vector<std::vector<composant_s>> wallList;
    std::vector<composant_s> element;

    for (const auto &it: _json["wall"].items()) {
        if (wallList.size() == 0 || isNewElementType(wallList, it.value()["type"].get<std::string>()) == true) {
            wallList.push_back(std::vector<composant_s>());
            wallList.back().push_back(createComposant(0,  std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), 0, 0, false, it.value()["type"].get<std::string>()));
        } else {
            for (auto &wall: wallList) {
                if (it.value()["type"].get<std::string>() == wall.front().type)
                    wall.push_back(createComposant(0,  std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), 0, 0, false, it.value()["type"].get<std::string>()));
            }
        }
    }
    _composantList.insert(_composantList.end(), wallList.begin(), wallList.end());
}

std::vector<std::vector<JsonWrapper::composant_s>> JsonWrapper::getComposantList() const
{
    return (_composantList);
}

void JsonWrapper::fillComposantList()
{
    addPlayer();
    addMonster();
    addWall();
}