#include "Game.hpp"
#include "Components.hpp"
#include "Constants.hpp"

rtype::Game::Game(std::vector<PlayerData>* players)
	: _jsonWrapper(std::string("Items/map.json")), _players(players), _r(2)
{
    std::cout << "in game ctor" << std::endl;
	//_registerComponents();
    //_setupComponents();
	//_initGame();
    /*for (;;) {
        if (players.size() == 4) {
            break;
        }
        std::this_thread::sleep_for(std::chrono::nanoseconds(100000));
    }
	_sendRequestsToAll();*/
}

//auto rtype::Game::_initGame() -> void
//{
//	std::vector<std::shared_ptr<rtype::Wall>> &wallList = _jsonWrapper.getWallList();
//    for (auto &it : wallList) {
//        it->init(_r);
//    }
//    std::vector<std::shared_ptr<rtype::Player>> &playerList = _jsonWrapper.getPlayerList();
//    for (auto &it : playerList) {
//        it->init(_r);
//    }
//    //std::vector<rtype::AMonster *> &monsterList = _jsonWrapper.getMonsterList();
//}

auto rtype::Game::runGame() -> void
{
    size_t nbPlayers = 0;
    std::cout << "running the game" << std::endl;
    for (;;) {
        if (nbPlayers != _players->size()) {
            nbPlayers = _players->size();
            std::cout << "players in the game : \'" << _players->size() << "\'" << std::endl;
        }
    }
	//std::cout << "Player List size : " << _jsonWrapper.getWallList().size() << std::endl;
}

//auto rtype::Game::_sendRequestsToAll() -> void
//{
//
//}
//
//auto rtype::Game::_registerComponents() -> void
//{
//    _r.registerComponent<components::myTime_s>(
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        },
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        });
//    _r.registerComponent<components::fireFrequence_s>(
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        },
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        });
//    _r.registerComponent<components::size_s>(
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        },
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        });
//    _r.registerComponent<components::healPoint_s>(
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        },
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        });
//    _r.registerComponent<components::loot_s>(
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        },
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        });
//    _r.registerComponent<components::position_s>(
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        },
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        });
//    _r.registerComponent<components::velocity_s>(
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        },
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        });
//    _r.registerComponent<components::weapon_s>(
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        },
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        });
//    _r.registerComponent<components::types_s>(
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        },
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        });
//    _r.registerComponent<components::index_s>(
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        },
//        [](Registry& r, Entity const& e) -> void
//        {
//            (void)r;
//            (void)e;
//        });
//}
//
//
//auto rtype::Game::_setupComponents() -> void
//{
//    _setupTimeComponent();
//}
//
//auto rtype::Game::_setupTimeComponent() -> void
//{
//    components::myTime_s time{};
//    _r.addComponent<components::myTime_s>(_r.entityFromIndex(rtype::constants::TIME_UPDATE), std::move(time));
//}