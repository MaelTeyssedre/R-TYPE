#include "Game.hpp"
#include "UpdateTime.hpp"
#include <thread>
#include <memory>
#include <chrono>

rtype::Game::Game(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer)
    : _r(Registry(2)), _roomBuffer(roomBuffer)
{
}

void rtype::Game::run()
{
    waitForStartingGame();
    setupGame();
    startGame();
}

void rtype::Game::setupGame()
{
    std::string wrapperFile("test.json");
    JsonWrapper wrapper(wrapperFile);

    registerMapObjectsComponents();
    registerTimeComponent();
    addTimeSystem();
    initMap(wrapper);
    sendMapRequest(wrapper);
    setupUpdateTimeSystem();
}

void rtype::Game::registerTimeComponent()
{
    _r.registerComponent<rtype::components::myTime_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
}

void rtype::Game::registerNetworkComponent()
{
    _r.registerComponent<rtype::components::network_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
}

void rtype::Game::addTimeSystem()
{
    components::myTime_s time{};
    _r.addComponent<components::myTime_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::TIME_UPDATE), std::move(time));
}

void rtype::Game::registerMapObjectsComponents()
{
    _r.registerComponent<rtype::components::fireFrequence_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<rtype::components::healPoint_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<rtype::components::loot_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<rtype::components::position_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<rtype::components::weapon_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<rtype::components::velocity_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
}

void rtype::Game::initMap(JsonWrapper &wrapper)
{
    std::vector<std::shared_ptr<Player>> listPlayers = wrapper.getPlayerList();
    std::vector<std::shared_ptr<Wall>> listWalls = wrapper.getWallList();
    std::vector<AMonster *> listMonsters = wrapper.getMonsterList();

    for (size_t i = 0; i < listPlayers.size(); i++)
        listPlayers[i]->init(_r);
    for (size_t i = 0; i < listWalls.size(); i++)
        listWalls[i]->init(_r);
    for (size_t i = 0; i < listMonsters.size(); i++)
        listMonsters[i]->init(_r);
}

void rtype::Game::sendMapRequest(JsonWrapper &wrapper)
{
    std::vector<uint8_t> vec;
    std::string jsonString = wrapper.jsonToString();
    vec.assign(jsonString.begin(), jsonString.end());
    for (size_t i = 0; i < (*_roomBuffer).size(); i++)
        ((*_roomBuffer)[i]).second.putInBuffer(vec.size(), vec);
}

void rtype::Game::waitForStartingGame()
{
    while (_roomBuffer->size() != 4)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void rtype::Game::startGame()
{
    _r.run_system();
}

void rtype::Game::setupUpdateTimeSystem()
{
    UpdateTime timeSystem{};
    _r.addSystem(std::move(timeSystem), _r.getComponents<components::myTime_s>());
}
