
#include "RtypeClient.hpp"

rtype::RtypeClient::RtypeClient(std::string host, std::string port)
    : _port(port), _host(host), _r(3), _netManager(NetworkManager()), _client(_netManager.createTCPClient(std::stoi(_port))), _socket(_netManager.createSocketUDP(std::stoi(_port))), _networkSystem(_client, _socket)
{
    registerComponents();
    setupTimeComponent();
    setupNetworkComponent();
    setupMouseStateComponent();
    setupKeyStateComponent();
    setupUpdateTimeSystem();
    setupUpdateNetworkSystem();
    setupUpdateGraphSystem();
}

void rtype::RtypeClient::run()
{
    for (;;)
        _r.run_system();
}

void rtype::RtypeClient::registerComponents()
{
    _r.registerComponent<components::myTime_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::network_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::mouseState_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::keyState_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
}

/*
 * Components 
*/

void rtype::RtypeClient::setupTimeComponent()
{
    components::myTime_s time{};
    _r.addComponent<components::myTime_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::TIME_UPDATE), std::move(time));
}

void rtype::RtypeClient::setupNetworkComponent()
{
    components::network_s network{};
    _r.addComponent<components::network_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::NETWORK_UPDATE), std::move(network));
}

void rtype::RtypeClient::setupMouseStateComponent()
{
    components::mouseState_s mouse{0, 0, false, false};
    _r.addComponent<components::mouseState_s>(_r.entityFromIndex(rtype::constants::RESERVED_ID::GRAPH_UPDATE), std::move(mouse));
}

void rtype::RtypeClient::setupKeyStateComponent()
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

void rtype::RtypeClient::setupUpdateTimeSystem()
{
    UpdateTime timeSystem{};
    _r.addSystem(std::move(timeSystem), _r.getComponents<components::myTime_s>());
}

void rtype::RtypeClient::setupUpdateNetworkSystem()
{
    _r.addSystem(_networkSystem, _r.getComponents<components::network_s>());
}

void rtype::RtypeClient::setupUpdateGraphSystem()
{
    UpdateGraph updateGraph{};
    _r.addSystem(std::move(updateGraph), _r.getComponents<components::mouseState_s>(), _r.getComponents<components::keyState_s>(), _r.getComponents<components::currentScene_s>());
}
