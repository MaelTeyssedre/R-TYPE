
#include "RtypeClient.hpp"

RtypeClient::RtypeClient(std::string host, std::string port)
    : _port(port), _host(host), _r(3)
{
    std::cout << "biteA" << std::endl;
    registerComponents();
    std::cout << "biteB" << std::endl;
    setupUpdateTimeSystem();
    std::cout << "biteC" << std::endl;
    setupUpdateNetworkSystem();
    std::cout << "biteD" << std::endl;
    setupUpdateGraphSystem();
    std::cout << "biteE" << std::endl;
}

void RtypeClient::run()
{
    for (;;) {
        std::cout << "bite" << std::endl;
        _r.run_system();
    }
}

void RtypeClient::registerComponents() {
    _r.registerComponent<components::myTime_t>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::network_t>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::mouseState_t>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    _r.registerComponent<components::keyState_t>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
}

/*
 * Components 
*/

void RtypeClient::setupTimeComponent()
{
    components::myTime_t time {};
    _r.addComponent<components::myTime_t>(_r.entityFromIndex(rtype::constants::RESERVED_ID::TIME_UPDATE), std::move(time));
}

void RtypeClient::setupNetworkComponent()
{
    components::network_t network {};
    _r.addComponent<components::network_t>(_r.entityFromIndex(rtype::constants::RESERVED_ID::NETWORK_UPDATE), std::move(network));
}

void RtypeClient::setupMouseStateComponent()
{
    components::mouseState_t mouse {0, 0, false, false};
    _r.addComponent<components::mouseState_t>(_r.entityFromIndex(rtype::constants::RESERVED_ID::GRAPH_UPDATE), std::move(mouse));
}

void RtypeClient::setupKeyStateComponent()
{
    components::keyState_t key {false, false, false, false, false, false,};
    _r.addComponent<components::keyState_t>(_r.entityFromIndex(rtype::constants::RESERVED_ID::GRAPH_UPDATE), std::move(key));
}

/*
 * Systems 
*/

void RtypeClient::setupUpdateTimeSystem()
{
    UpdateTime timeSystem {};
    _r.addSystem(timeSystem, _r.getComponents<components::myTime_t>());
}

void RtypeClient::setupUpdateNetworkSystem()
{
    UpdateNetwork networkSystem {_netManager.createTCPClient(std::stoi(_port)), _netManager.createSocketUDP(std::stoi(_port))};
    _r.addSystem(networkSystem, _r.getComponents<components::network_t>());
}

void RtypeClient::setupUpdateGraphSystem()
{
    UpdateGraph updateGraph {};
    _r.addSystem(updateGraph, _r.getComponents<components::mouseState_t>(), _r.getComponents<components::keyState_t>());
}
