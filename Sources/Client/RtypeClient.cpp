
#include "RtypeClient.hpp"

bool rtype::RtypeClient::_status = true;

rtype::RtypeClient::RtypeClient(std::string host, std::string port)
    : _port(port), _host(host), _r(3), _netManager(NetworkManager()), _client(_netManager.createTCPClient(std::stoi(_port))), _socket(_netManager.createSocketUDP(std::stoi(_port))), _networkSystem(_client, _socket)
{
    if (_client->isConnected() == false)
        return;
    _status = true;
    _registerComponents();
    _setupComponents();
    _setupSystems();
}

void rtype::RtypeClient::run()
{
    signal(SIGINT, rtype::RtypeClient::signalHandler);
    while (_status == true)
        _r.run_system();
}

void rtype::RtypeClient::signalHandler(int signum)
{
    (void)signum;
    std::cout << "Goodbye" << std::endl;
    _status = false;
}

void rtype::RtypeClient::_registerComponents()
{
    _r.registerComponent<components::myTime_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::network_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::mouseState_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::keyState_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::currentScene_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::direction_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::entityType_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::health_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::position_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::reserved_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::scene_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::index_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::mySize_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::strength_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::velocity_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::weaponType_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::clickable_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::sprite_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::scene_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::drawable_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::music_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::zaxis_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::text_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
    _r.registerComponent<components::color_s>([](Registry &r, Entity const &e) -> void {}, [](Registry &r, Entity const &e) -> void {});
}

void rtype::RtypeClient::_setupComponents()
{
    _setupTimeComponent();
    _setupNetworkComponent();
    _setupMouseStateComponent();
    _setupKeyStateComponent();
    _setupCurrentSceneComponent();
}

void rtype::RtypeClient::_setupSystems() {
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

void rtype::RtypeClient::_setupCurrentSceneComponent()
{
    _r.addComponent<components::currentScene_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::GRAPH_UPDATE), {constants::SCENE::LOADING_MENU, false});
}

void rtype::RtypeClient::_setupTimeComponent()
{
    components::myTime_s time{};
    _r.addComponent<components::myTime_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::TIME_UPDATE), std::move(time));
}

void rtype::RtypeClient::_setupNetworkComponent()
{
    components::network_s network{};
    _r.addComponent<components::network_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::NETWORK_UPDATE), std::move(network));
}

void rtype::RtypeClient::_setupMouseStateComponent()
{
    components::mouseState_s mouse {0, 0, false, false};
    _r.addComponent<components::mouseState_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::GRAPH_UPDATE), std::move(mouse));
}

void rtype::RtypeClient::_setupKeyStateComponent()
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

void rtype::RtypeClient::_setupUpdatePositionSystem()
{
    UpdatePosition posSystem {};
    _r.addSystem(std::move(posSystem), _r.getComponents<components::position_s>(), _r.getComponents<components::direction_s>(), _r.getComponents<components::velocity_s>());
}

void rtype::RtypeClient::_setupUpdateTimeSystem()
{
    UpdateTime timeSystem{};
    _r.addSystem(std::move(timeSystem), _r.getComponents<components::myTime_s>());
}

void rtype::RtypeClient::_setupUpdateNetworkSystem()
{
    _r.addSystem(_networkSystem, _r.getComponents<components::network_s>());
}

void rtype::RtypeClient::_setupUpdateDirectionSystem()
{
    UpdateDirection dirSystem {};
    _r.addSystem(std::move(dirSystem), _r.getComponents<components::direction_s>(), _r.getComponents<components::keyState_s>());
}

void rtype::RtypeClient::_setupUpdateGraphSystem()
{
    //UpdateGraph graphSystem {};
    _r.addSystem(_graphSystem, _r.getComponents<components::mouseState_s>(), _r.getComponents<components::keyState_s>(), _r.getComponents<components::currentScene_s>());
}

void rtype::RtypeClient::_setupUpdateScene()
{
    //UpdateGraph graphSystem {};
    _r.addSystem(_graphSystem, _r.getComponents<components::mouseState_s>(), _r.getComponents<components::keyState_s>(), _r.getComponents<components::currentScene_s>());
}

bool rtype::RtypeClient::checkStatus()
{
    return (_status);
}

void rtype::RtypeClient::_setupUpdateClickable()
{
    UpdateClickable clickable {};
    _r.addSystem(std::move(clickable), _r.getComponents<components::clickable_s>(), _r.getComponents<components::mouseState_s>(), _r.getComponents<components::position_s>(),  _r.getComponents<components::mySize_s>(), _r.getComponents<components::index_s>(), _r.getComponents<components::scene_s>());
}