#include "Game.hpp"
#include "Components.hpp"
#include "Constants.hpp"

rtype::Game::Game(std::vector<PlayerData>* players)
	: _jsonWrapper(std::string("Items/map.json")), _players(players), _r(2)
{
	_registerComponents();
    _setupComponents();
	_initGame();
}


//TODO add type


auto rtype::Game::_initGame() -> void
{
	std::vector<std::shared_ptr<rtype::Wall>> &wallList = _jsonWrapper.getWallList();
    for (auto &it : wallList) {
        it->init(_r);
    }
    std::vector<std::shared_ptr<rtype::Player>> &playerList = _jsonWrapper.getPlayerList();
    for (auto &it : playerList) {
        it->init(_r);
    }
    std::vector<rtype::AMonster *> &monsterList = _jsonWrapper.getMonsterList();
    for (auto &it : monsterList) {
        _registerMonster(it);
    }
}

auto rtype::Game::runGame() -> void
{
	std::cout << "Player List size : " << _jsonWrapper.getWallList().size() << std::endl;
}

auto rtype::Game::_registerMonster(rtype::AMonster *monster) ->void
{
    Entity idx = _r.spawnEntity();
    struct rtype::components::index_s index {(size_t)idx};

    _r.addComponent<rtype::components::position_s>(_r.entityFromIndex(idx), monster->getPosition());
	_r.addComponent<rtype::components::velocity_s>(_r.entityFromIndex(idx), monster->getVelocity());
	_r.addComponent<rtype::components::weapon_s>(_r.entityFromIndex(idx), monster->getWeapon());
	_r.addComponent<rtype::components::healPoint_s>(_r.entityFromIndex(idx), monster->getHealPoint());
	_r.addComponent<rtype::components::fireFrequence_s>(_r.entityFromIndex(idx), monster->getFireFrequence());
	_r.addComponent<rtype::components::index_s>(_r.entityFromIndex(idx), std::move(index));
}

auto rtype::Game::_registerComponents() -> void
{
    _r.registerComponent<components::myTime_s>(
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::fireFrequence_s>(
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::healPoint_s>(
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::loot_s>(
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::position_s>(
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::velocity_s>(
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::weapon_s>(
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::types_s>(
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry& r, Entity const& e) -> void
        {
            (void)r;
            (void)e;
        });
}


auto rtype::Game::_setupComponents() -> void
{
    _setupTimeComponent();
}

auto rtype::Game::_setupTimeComponent() -> void
{
    components::myTime_s time{};
    _r.addComponent<components::myTime_s>(_r.entityFromIndex(rtype::constants::TIME_UPDATE), std::move(time));
}