#include "JsonWrapper.hpp"

JsonWrapper::JsonWrapper(std::string &filename)
{
    _filename = filename;
    std::ifstream ifs(_filename);
    _json = nlohmann::json::parse(ifs);
    std::cout << "monster to load : " << _json["monster"].size() << std::endl;
    for (size_t i = 0; i < _json["monster"].size(); i++) {
        _typeList.push_back(_json["monster"][i]["type"]);
        object_t obj { _json["monster"][i]["id"], std::pair(_json["monster"][i]["pos"][0],  _json["monster"][i]["pos"][1]), _json["monster"][i]["hp"], _json["monster"][i]["strength"], _json["monster"][i]["type"]};
        _params.push_back(std::pair<std::string, object_t>(_json["monster"][i]["type"], obj));
    }
    fillComposantList();
}

std::string JsonWrapper::jsonToString()
{
    return (_json.dump(4));
}

std::shared_ptr<Player> JsonWrapper::createPlayer(int id, std::pair<int, int> pos, int strength, int hp, std::string type)
{
    (void) id;
    (void) pos;
    (void) strength;
    (void) hp;
    std::shared_ptr<Player> element {new Player()};
    element->setName(type);
    return (element);
}

std::shared_ptr<Wall> JsonWrapper::createWall(std::pair<int, int> pos, std::string type)
{
    (void) pos;
    std::shared_ptr<Wall> element {new Wall()};
    element->setName(type);
    return (element);
}

void JsonWrapper::addPlayer()
{
    for (size_t i = 0; i < _json["player"].size(); i++)
        _playerList.push_back(createPlayer(_json["player"][i]["id"], std::make_pair(_json["player"][i]["pos"][0], _json["player"][i]["pos"][1]), _json["player"][i]["strength"], _json["player"][i]["hp"], std::string("player")));
}

void JsonWrapper::addMonster()
{
    _loader.loadLibs(_typeList);
    std::vector<std::shared_ptr<AMonster>> *dylibs = _loader.getLibs(); 

    for (size_t i = 0; i < _json["monster"].size(); i++) {
        _monsterList.push_back(((*dylibs)[i].get()));
    }
}

void JsonWrapper::addWall()
{
    for (size_t i = 0; i < _json["wall"].size(); i++)
        _wallList.push_back(createWall(std::make_pair(_json["wall"][i]["pos"][0], _json["wall"][i]["pos"][1]), _json["wall"][i]["type"]));
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