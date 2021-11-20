#include "JsonWrapper.hpp"

JsonWrapper::JsonWrapper(std::string &filename)
{
    _filename = filename;
    std::ifstream ifs(_filename);
    _json = nlohmann::json::parse(ifs);
    for (auto it : _json["monster"].items()) {
        for (auto &it2 : it.value()) {
            _typeList.push_back(it.value()["type"].get<std::string>());
            object_t obj {  it.value()["id"].get<int>(), 
                            std::pair( it.value()["pos"][0].get<int>(),  it.value()["pos"][1].get<int>()), 
                            it.value()["hp"].get<int>(), 
                            it.value()["strength"].get<int>(), 
                            it.value()["type"].get<std::string>()
                        };
            _params.push_back(std::pair<std::string, object_t>(it.value()["type"].get<std::string>(), obj));
        }
    }
    fillComposantList();
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

    std::cout << dylibs.size() << std::endl;
    std::cout << _typeList.size() << std::endl;
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

    int j = 0;
    for (size_t i = 0; i != _objectList.size(); i++) {
        if (_objectList[i].second != "basic_monster") {
            AMonster *ptr = dynamic_cast<AMonster *>(_objectList[i].first.get());
            (*ptr).getName();
            std::cout << "I'm the smartest dog in the world" << std::endl;
            std::cout << _params[j].second.type << std::endl;
            (*ptr).setName(_params[j].second.type);
            std::cout << "I'm the smartest dog in the world" << std::endl;
            (*ptr).setWeapon(_params[j].second.strength);
            std::cout << "I'm the smartest dog in the world" << std::endl;
            (*ptr).setHealPoint(_params[j].second.hp);
            std::cout << "I'm the smartest dog in the world" << std::endl;
            (*ptr).setPosition(_params[j].second.pos);
            std::cout << "I'm the smartest dog in the world" << std::endl;
            j++;
            std::cout << "I'm the greatest dog in the world" << std::endl;
        }
    }
}

nlohmann::json JsonWrapper::strToJson(std::string &toConvert)
{
    _json = nlohmann::json::parse(toConvert);
    return (_json);
}