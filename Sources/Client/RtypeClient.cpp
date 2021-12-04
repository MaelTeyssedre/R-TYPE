
#include "RtypeClient.hpp"

bool rtype::RtypeClient::_status = true;

rtype::RtypeClient::RtypeClient(std::string host, std::string port)
    : _port(port), _host(host), _r(3), _netManager(NetworkManager()), _client(_netManager.createTCPClient(host, std::stoi(_port))), _socket(_netManager.createSocketUDP(host, std::stoi(_port))), _networkSystem(_client, _socket)
{
    if (_client->isConnected() == false)
        return;
    _status = true;
    _registerComponents();
    _setupComponents();
    _setupSystems();
}

auto rtype::RtypeClient::run() -> void
{
    signal(SIGINT, rtype::RtypeClient::signalHandler);
    while (_status == true)
        _r.run_system();
}

auto rtype::RtypeClient::signalHandler(int signums) -> void
{
    (void)signums;
    _status = false;
}

auto rtype::RtypeClient::_registerComponents() -> void
{
    _r.registerComponent<components::myTime_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::network_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::mouseState_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::keyState_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::currentScene_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::direction_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::entityType_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::health_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::position_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::reserved_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::scene_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::index_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::mySize_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::strength_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::velocity_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::weaponType_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::clickable_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::sprite_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::scene_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::drawable_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::music_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::zaxis_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::text_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::color_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::playerList_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
     _r.registerComponent<components::roomList_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
    _r.registerComponent<components::playerData_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
        _r.registerComponent<components::roomData_s>(
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        },
        [](Registry &r, Entity const &e) -> void
        {
            (void)r;
            (void)e;
        });
}

auto rtype::RtypeClient::_setupComponents() -> void
{
    _setupTimeComponent();
    _setupNetworkComponent();
    _setupMouseStateComponent();
    _setupKeyStateComponent();
    _setupCurrentSceneComponent();
}

auto rtype::RtypeClient::_setupSystems() -> void
{
    _setupUpdateTimeSystem();
    _setupUpdateNetworkSystem();
    _setupUpdateGraphSystem();
    _setupUpdateDirectionSystem();
    _setupUpdatePositionSystem();
    _setupUpdateClickable();
}

/*
 * Components 
 */

auto rtype::RtypeClient::_setupCurrentSceneComponent() -> void
{
    _r.addComponent<components::currentScene_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::GRAPH_UPDATE), {constants::SCENE::LOADING_MENU, false});
}

auto rtype::RtypeClient::_setupTimeComponent() -> void
{
    components::myTime_s time{};
    _r.addComponent<components::myTime_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::TIME_UPDATE), std::move(time));
}

auto rtype::RtypeClient::_setupNetworkComponent() -> void
{
    components::network_s network{
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{},
        std::vector<std::vector<uint8_t>>{} // ! send
    };

    _r.addComponent<components::network_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::NETWORK_UPDATE), std::move(network));
}

auto rtype::RtypeClient::_setupMouseStateComponent() -> void
{
    components::mouseState_s mouse{0, 0, false, false};
    _r.addComponent<components::mouseState_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::GRAPH_UPDATE), std::move(mouse));
}

auto rtype::RtypeClient::_setupKeyStateComponent() -> void
{
    components::keyState_s key{
        false,
        false,
        false,
        false,
        false,
        false,
    };
    _r.addComponent<components::keyState_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::GRAPH_UPDATE), std::move(key));
}

/*
 * Systems 
 */

auto rtype::RtypeClient::_setupUpdatePositionSystem() -> void
{
    UpdatePosition posSystem{};
    _r.addSystem(std::move(posSystem), _r.getComponents<components::position_s>(), _r.getComponents<components::direction_s>(), _r.getComponents<components::velocity_s>());
}

auto rtype::RtypeClient::_setupUpdateTimeSystem() -> void
{
    UpdateTime timeSystem{};
    _r.addSystem(std::move(timeSystem), _r.getComponents<components::myTime_s>());
}

auto rtype::RtypeClient::_setupUpdateNetworkSystem() -> void
{
    _r.addSystem(_networkSystem, _r.getComponents<components::network_s>());
}

auto rtype::RtypeClient::_setupUpdateDirectionSystem() -> void
{
    UpdateDirection dirSystem{};
    _r.addSystem(std::move(dirSystem), _r.getComponents<components::direction_s>(), _r.getComponents<components::keyState_s>());
}

auto rtype::RtypeClient::_setupUpdateGraphSystem() -> void
{
    //UpdateGraph graphSystem {};
    _r.addSystem(_graphSystem, _r.getComponents<components::mouseState_s>(), _r.getComponents<components::keyState_s>(), _r.getComponents<components::currentScene_s>());
}

auto rtype::RtypeClient::_setupUpdateScene() -> void
{
    //UpdateGraph graphSystem {};
    _r.addSystem(_graphSystem, _r.getComponents<components::mouseState_s>(), _r.getComponents<components::keyState_s>(), _r.getComponents<components::currentScene_s>());
}

auto rtype::RtypeClient::checkStatus() -> bool
{
    return (_status);
}

auto rtype::RtypeClient::_setupUpdateClickable() -> void
{
    UpdateClickable clickable{};
    _r.addSystem(std::move(clickable), _r.getComponents<components::clickable_s>(), _r.getComponents<components::mouseState_s>(), _r.getComponents<components::position_s>(), _r.getComponents<components::mySize_s>(), _r.getComponents<components::index_s>(), _r.getComponents<components::scene_s>(), _r.getComponents<components::currentScene_s>(), _r.getComponents<components::sprite_s>());
}