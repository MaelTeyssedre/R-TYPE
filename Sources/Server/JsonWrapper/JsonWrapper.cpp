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


JsonWrapper::JsonWrapper(std::string &filename)
{
    _filename = filename;
    std::ifstream ifs(_filename);
    _json = nlohmann::json::parse(ifs);
    fillComposantList();
}

std::string JsonWrapper::jsonToString()
{
    return (_json.dump(4));
}

bool JsonWrapper::isNewElementType(std::vector<std::vector<JsonWrapper::object_s>> _objectList, std::string type)
{
    for (auto &composant : _objectList)
        if (type == composant.front().type)
            return (false);
    return (true);
}

JsonWrapper::object_s JsonWrapper::createComposant(int id, std::pair<int, int> pos, int strength, int hp, const std::string &type)
{
    JsonWrapper::object_s element;

    element.id = id;
    element.pos = pos;
    element.strength = strength;
    element.hp = hp;
    element.type = type;
    return (element);
}

JsonWrapper::object_s JsonWrapper::createComposant(std::pair<int, int> pos, const std::string &type)
{
    JsonWrapper::object_s element;

    element.pos = pos;
    element.type = type;
    return (element);
}

void JsonWrapper::addPlayer()
{
    std::vector<JsonWrapper::object_s> playerList;

    for (auto it: _json["player"].items())
        playerList.push_back(createComposant(it.value()["id"].get<int>(), std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["strength"].get<int>(), it.value()["hp"].get<int>(), std::string("player")));
    _objectList.push_back(playerList);
}

void JsonWrapper::addMonster()
{
    std::vector<std::vector<JsonWrapper::object_s>> monsterList;
    std::vector<JsonWrapper::object_s> element;

    for (auto it: _json["monster"].items()) {
        if (monsterList.size() == 0 || isNewElementType(monsterList, it.value()["type"].get<std::string>()) == true) {
            monsterList.push_back(std::vector<JsonWrapper::object_s>());
            monsterList.back().push_back(createComposant(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>()));
        } else {
            for (auto &monster: monsterList)
                if (it.value()["type"].get<std::string>() == monster.front().type)
                    monster.push_back(createComposant(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>())); 
        }
    }
    _objectList.insert(_objectList.end(), monsterList.begin(), monsterList.end());
}

void JsonWrapper::addWall()
{
    std::vector<std::vector<JsonWrapper::object_s>> wallList;
    std::vector<JsonWrapper::object_s> element;

    for (auto it: _json["wall"].items()) {
        if (wallList.size() == 0 || isNewElementType(wallList, it.value()["type"].get<std::string>()) == true) {
            wallList.push_back(std::vector<JsonWrapper::object_s>());
            wallList.back().push_back(createComposant(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>()));
        } else {
            for (auto &wall: wallList)
                if (it.value()["type"].get<std::string>() == wall.front().type) {
                    wall.push_back(createComposant(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>()));
                }
        }
    }
    _objectList.insert(_objectList.end(), wallList.begin(), wallList.end());
}

std::vector<std::vector<JsonWrapper::object_s>> JsonWrapper::getComposantList() const
{
    return (_objectList);
}

void JsonWrapper::fillComposantList()
{
    addPlayer();
    addMonster();
    addWall();
}