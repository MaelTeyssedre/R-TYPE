#include "JsonWrapper.hpp"

rtype::JsonWrapper::JsonWrapper(std::string &filename)
{
    _filename = filename;
    std::ifstream ifs(_filename);
    _json = nlohmann::json::parse(ifs);
    for (size_t i = 0; i < _json["monster"].size(); i++)
    {
        _typeList.push_back(_json["monster"][i]["type"]);
        object_t obj{_json["monster"][i]["id"], std::pair(_json["monster"][i]["pos"][0], _json["monster"][i]["pos"][1]), _json["monster"][i]["hp"], _json["monster"][i]["strength"], _json["monster"][i]["type"]};
        _params.push_back(std::pair<std::string, object_t>(_json["monster"][i]["type"], obj));
    }
    fillComposantList();
}

std::string rtype::JsonWrapper::jsonToString()
{
    return (_json.dump(0));
}

std::vector<rtype::AMonster *> &rtype::JsonWrapper::getMonsterList()
{
    return _monsterList;
}

std::vector<std::shared_ptr<rtype::Player>> &rtype::JsonWrapper::getPlayerList()
{
    return _playerList;
}

std::vector<std::shared_ptr<rtype::Wall>> &rtype::JsonWrapper::getWallList()
{
    return _wallList;
}

std::shared_ptr<rtype::Player> rtype::JsonWrapper::createPlayer(int id, std::pair<int, int> pos, int strength, int hp, std::string type)
{
    (void)id;
    (void)pos;
    (void)strength;
    (void)hp;
    std::shared_ptr<rtype::Player> element{new Player()};
    element->setName(type);
    return (element);
}

std::shared_ptr<rtype::Wall> rtype::JsonWrapper::createWall(std::pair<int, int> pos, std::string type)
{
    (void)pos;
    std::shared_ptr<Wall> element {new Wall()};
    element->setName(type);
    return (element);
}

void rtype::JsonWrapper::addPlayer()
{
    for (size_t i = 0; i < _json["player"].size(); i++)
        _playerList.push_back(createPlayer(_json["player"][i]["id"], std::make_pair(_json["player"][i]["pos"][0], _json["player"][i]["pos"][1]), _json["player"][i]["strength"], _json["player"][i]["hp"], std::string("player")));
}

void rtype::JsonWrapper::addMonster()
{
    _loader.loadLibs(_typeList);
    std::vector<std::shared_ptr<rtype::AMonster>> *dylibs = _loader.getLibs();
    for (size_t i = 0; i < _json["monster"].size(); i++)
    {
        _monsterList.push_back(((*dylibs)[i].get()));
    }
}

void rtype::JsonWrapper::addWall()
{
    for (size_t i = 0; i < _json["wall"].size(); i++)
        _wallList.push_back(createWall(std::make_pair(_json["wall"][i]["pos"][0], _json["wall"][i]["pos"][1]), _json["wall"][i]["type"]));
}

void rtype::JsonWrapper::fillComposantList()
{
    addPlayer();
    addMonster();
    addWall();
}

nlohmann::json rtype::JsonWrapper::strToJson(std::string &toConvert)
{
    _json = nlohmann::json::parse(toConvert);
    return (_json);
}