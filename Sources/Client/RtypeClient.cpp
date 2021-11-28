
#include "RtypeClient.hpp"

rtype::RtypeClient::RtypeClient(std::string host, std::string port)
    : _port(port), _host(host), _r(3), _netManager(NetworkManager()), _client(_netManager.createTCPClient(std::stoi(_port))), _socket(_netManager.createSocketUDP(std::stoi(_port))), _networkSystem(_client, _socket)
{
    _registerComponents();
    _setupComponents();
    _setupSystems();
}

void rtype::RtypeClient::run()
{
    for (;;)
        _r.run_system();
}

void rtype::RtypeClient::_registerComponents()
{
    _r.registerComponent<components::myTime_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::network_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::mouseState_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::keyState_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::currentScene_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::direction_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::entityType_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::health_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::position_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::reserved_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::scene_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::mySize_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::strength_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::velocity_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::weaponType_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
}

void rtype::RtypeClient::_setupComponents()
{
    _setupTimeComponent();
    _setupNetworkComponent();
    _setupMouseStateComponent();
    _setupKeyStateComponent();
}

void rtype::RtypeClient::_setupSystems() {
    _setupUpdateTimeSystem();
    _setupUpdateNetworkSystem();
    _setupUpdateGraphSystem();
    _setupUpdateDirectionSystem();
    _setupUpdatePositionSystem();
}

/*
 * Components 
 */

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
    components::mouseState_s mouse{0, 0, false, false};
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
    _r.addSystem(_graphSystem, _r.getComponents<components::mouseState_s>(), _r.getComponents<components::keyState_s>(), _r.getComponents<components::currentScene_s>());
}
