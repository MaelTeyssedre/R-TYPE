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
#include "Wall.hpp"
#include "Player.hpp"


JsonWrapper::JsonWrapper(std::string &filename)
{
    _filename = filename;
    std::ifstream ifs(_filename);
    _json = nlohmann::json::parse(ifs);
    fillComposantList();
    for (auto it : _json["monster"].items()) {
        for (auto &it2 : it)
            _typeList.push_back(it.value()["type"].get<std::string>());
    }
}

std::string JsonWrapper::jsonToString()
{
    return (_json.dump(4));
}

bool JsonWrapper::isNewElementType(std::vector<std::vector<std::shared_ptr<IElement>>> _objectList, std::string type)
{
    for (auto &composant : _objectList)
        if (type == composant.front()->getName())
            return (false);
    return (true);
}

std::shared_ptr<IElement> JsonWrapper::createPlayer(int id, std::pair<int, int> pos, int strength, int hp, std::string type)
{
    std::shared_ptr<Player> element = std::make_shared<Player>();
    component::position_s position;
    component::weapon_s weapon;
    component::healPoint_s healPoint;

    position.x = pos.first;
    position.y = pos.second;
    weapon.weaponType = strength;
    healPoint.healPoint = hp;
    element->setPosition(position);
    element->setWeapon(weapon);
    element->setHealPoint(healPoint);
    element->setName(type);
    return (element);
}

std::shared_ptr<IElement> JsonWrapper::createWall(std::pair<int, int> pos, std::string type)
{
    std::shared_ptr<Wall> element;
    component::position_s position;

    position.x = pos.first;
    position.y = pos.second;
    element->setPosition(position);
    element->setName(type);
    return (element);
}

std::shared_ptr<IElement> JsonWrapper::createMonster(std::pair<int, int> pos, std::string type)
{
    std::shared_ptr<AMonster> element = std::make_shared<BalkanyMonster>();
    component::position_s position;

    position.x = pos.first;
    position.y = pos.second;
    element->setPosition(position);
    element->setName(type);
    return (element);
}

void JsonWrapper::addPlayer()
{
    std::vector<std::shared_ptr<IElement>> playerList;

    for (auto it: _json["player"].items())
        playerList.push_back(createPlayer(it.value()["id"].get<int>(), std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["strength"].get<int>(), it.value()["hp"].get<int>(), std::string("player")));
    _objectList.push_back(playerList);
}

void JsonWrapper::addMonster()
{
    LibLoader loader(_typeList);
    std::vector<std::shared_ptr<IElement>> dylibs = loader.getLibs(); 
    std::vector<std::vector<std::shared_ptr<IElement>>> monsterList;
    std::vector<std::shared_ptr<IElement>> element;

    for (auto it: _json["monster"].items()) {
        if (monsterList.size() == 0 || isNewElementType(monsterList, it.value()["type"].get<std::string>()) == true) {
            monsterList.push_back(std::vector<std::shared_ptr<IElement>>());
            monsterList.back().push_back(std::make_shared<IElement>(createMonster(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>())));
        } else {
            for (auto &monster: monsterList)
                if (it.value()["type"].get<std::string>() == monster.front()->getName())
                    monster.push_back(std::make_shared<IElement>(createMonster(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>()))); 
        }
    }
    _objectList.insert(_objectList.end(), monsterList.begin(), monsterList.end());
}

void JsonWrapper::addWall()
{
    std::vector<std::vector<std::shared_ptr<IElement>>> wallList;
    std::vector<std::shared_ptr<IElement>> element;

    for (auto it: _json["wall"].items()) {
        if (wallList.size() == 0 || isNewElementType(wallList, it.value()["type"].get<std::string>()) == true) {
            wallList.push_back(std::vector<std::shared_ptr<IElement>>());
            wallList.back().push_back(std::make_shared<IElement>(createWall(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>())));
        } else {
            for (auto &wall: wallList)
                if (it.value()["type"].get<std::string>() == wall.front()->getName()) {
                    wall.push_back(std::make_shared<IElement>(std::make_shared<IElement>(createWall(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>()))));
                }
        }
    }
    _objectList.insert(_objectList.end(), wallList.begin(), wallList.end());
}

std::vector<std::vector<std::shared_ptr<IElement>>> JsonWrapper::getComposantList() const
{
    return (_objectList);
}

void JsonWrapper::fillComposantList()
{
    addPlayer();
    addMonster();
    addWall();
}

nlohmann::json JsonWrapper::strToJson(std::string &toConvert)
{
    _json = nlohmann::json::parse(toConvert);
    return (_json);
}