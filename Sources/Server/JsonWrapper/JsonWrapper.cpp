#include "JsonWrapper.hpp"

JsonWrapper::JsonWrapper(std::string &filename)
{
    _filename = filename;
    std::ifstream ifs(_filename);
    _json = nlohmann::json::parse(ifs);
    fillComposantList();
    for (nlohmann::detail::iteration_proxy_value<nlohmann::detail::iter_impl<nlohmann::json>> it : _json["monster"].items())
        for (nlohmann::json &it2 : it.value())
            _typeList.push_back(it.value()["type"].get<std::string>());
            // _params.push_back(std::make_pair<std::string, object_t>(it.value()["type"].get<std::string>(), {it.value()["id"].get<int>(), std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][0].get<int>()), it.value()["strength"].get<int>(), it.value()["hp"].get<int>(), it.value()["type"].get<std::string>()}));
        // }
}

std::string JsonWrapper::jsonToString()
{
    return (_json.dump(4));
}

// bool JsonWrapper::isNewElementType(std::vector<std::vector<std::shared_ptr<IElement>>> _objectList, std::string type)
// {
//     for (std::vector<std::shared_ptr<IElement>> &composant : _objectList)
//         if (type == composant.front()->getName())
//             return (false);
//     return (true);
// }

std::shared_ptr<IElement> JsonWrapper::createPlayer(int id, std::pair<int, int> pos, int strength, int hp, std::string type)
{
    std::shared_ptr<Player> element = std::make_shared<Player>();
    // component::position_s position;
    // component::weapon_s weapon;
    // component::healPoint_s healPoint;

    // position.x = pos.first;
    // position.y = pos.second;
    // weapon.weaponType = strength;
    // healPoint.healPoint = hp;
    // element->setPosition(position);
    // element->setWeapon(weapon);
    // element->setHealPoint(healPoint);
    element->setName(type);
    return (element);
}

std::shared_ptr<IElement> JsonWrapper::createWall(std::pair<int, int> pos, std::string type)
{
    std::shared_ptr<Wall> element;
    // component::position_s position;

    // position.x = pos.first;
    // position.y = pos.second;
    // element->setPosition(position);
    element->setName(type);
    return (element);
}

// std::shared_ptr<IElement> JsonWrapper::createMonster(std::pair<int, int> pos, std::string type)
// {
//     // std::shared_ptr<AMonster> element = std::make_shared<BalkanyMonster;
//     // component::position_s position;

//     // position.x = pos.first;
//     // position.y = pos.second;
//     // element->setPosition(position);
//     // element->setName(type);
//     // return (element);
// }

void JsonWrapper::addPlayer()
{
    // std::vector<std::shared_ptr<IElement>> playerList;

    for (auto it: _json["player"].items())
        _objectList.push_back(std::pair(createPlayer(it.value()["id"].get<int>(), std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["strength"].get<int>(), it.value()["hp"].get<int>(), std::string("player")), std::string("player")));
    // _objectList.push_back(playerList);
}

void JsonWrapper::addMonster()
{
    LibLoader loader(_typeList);
    std::vector<std::shared_ptr<IElement>> dylibs = loader.getLibs(); 
    // std::vector<std::pair<std::shared_ptr<IElement>, std::string>> monsterList;
    // std::vector<std::shared_ptr<IElement>> element;

    for (size_t i = 0; i < dylibs.size() && i < _typeList.size(); i++)
        for (auto it: _json["monster"].items())
            _objectList.push_back(std::pair(std::shared_ptr(dylibs[i]), _typeList[i]));
                // monsterList.back().push_back(std::make_shared<IElement>(createMonster(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>())));
            // } else {
            //     for (auto &monster: monsterList)
            //         if (it.value()["type"].get<std::string>() == monster.front().first->getName())
            //             monster.push_back(std::make_shared<IElement>(createMonster(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>()))); 
            // }
    // _objectList.insert(_objectList.end(), monsterList.begin(), monsterList.end());
}

void JsonWrapper::addWall()
{
    // std::vector<std::vector<std::shared_ptr<IElement>>> wallList;
    // std::vector<std::shared_ptr<IElement>> element;

    for (auto it: _json["wall"].items())
            _objectList.push_back(std::pair(createWall(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>()), std::string("wall")));
        // } else {
            // for (auto &wall: wallList)
                // if (it.value()["type"].get<std::string>() == wall.front()->getName()) {
                    // wall.push_back(std::make_shared<IElement>(std::make_shared<IElement>(createWall(std::make_pair(it.value()["pos"][0].get<int>(), it.value()["pos"][1].get<int>()), it.value()["type"].get<std::string>()))));
                // }
        // }
    // }
    // _objectList.insert(_objectList.end(), wallList.begin(), wallList.end());
}

std::vector<std::pair<std::shared_ptr<IElement>, std::string>> &JsonWrapper::getComposantList()
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