/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** JsonWrapper
*/

#include <string>
#include <iostream>
#include <fstream>
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

void JsonWrapper::createJsonFromString(std::string &string)
{
    _json = nlohmann::json::parse(string);
    
}