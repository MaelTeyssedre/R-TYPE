#include "Game.hpp"

rtype::Game::Game(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer)
    : _r(Registry(2)), _roomBuffer(roomBuffer)
{
}

void rtype::Game::run() {
    waitForStartingGame();
    setupGame();
    startGame();
}

void rtype::Game::setupGame()
{
    JsonWrapper wrapper(std::string("test.json"));
    std::vector<uint8_t> vec;
    std::vector<std::shared_ptr<Player>> listPlayers = wrapper.getPlayerList();
    std::vector<std::shared_ptr<Wall>> listWalls = wrapper.getWallList();
    std::vector<AMonster *> listMonsters = wrapper.getMonsterList();

    _r.registerComponent<rtype::components::fireFrequence_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<rtype::components::healPoint_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<rtype::components::loot_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<rtype::components::position_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<rtype::components::weapon_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<rtype::components::velocity_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    for (size_t i = 0; i < listPlayers.size(); i++)
        listPlayers[i]->init(_r);
    for (size_t i = 0; i < listWalls.size(); i++)
        listWalls[i]->init(_r);
    for (size_t i = 0; i < listMonsters.size(); i++)
        listMonsters[i]->init(_r);
    std::string jsonString = wrapper.jsonToString();
    vec.assign(jsonString.begin(), jsonString.end());
    for (size_t i = 0; i < (*_roomBuffer).size(); i++)
        ((*_roomBuffer)[i]).second.putInBuffer(vec.size(), vec);
}

void rtype::Game::waitForStartingGame()
{
    while (_roomBuffer->size() != 4)
        std::this_thread::sleep_for(std::chrono::seconds(1));
}

void rtype::Game::startGame()
{
    std::cout << "In start Game" << std::endl;
}