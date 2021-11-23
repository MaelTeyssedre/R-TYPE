
#include "RtypeClient.hpp"

RtypeClient::RtypeClient(std::string host, std::string port)
    : _port(port), _host(host), _r(4)
{
    setupUpdateTimeSystem();
    setupUpdateNetworkSystem();
    setupUpdateEventSystem();
    setupUpdateGraphSystem();
}

void RtypeClient::run() {
    for (;;)
        _r.run_system();
}

/*
 * Components 
*/

components::myTime_t setupTimeComponent() {
    
}

components::network_t setupNetworkComponent() {

}

components::mouseState_t setupMouseStateComponent() {

}

components::keyState_t setupKeyStateComponent() {
    
}

/*
 * Systems 
*/

void RtypeClient::setupUpdateTimeSystem() {
    
    _r.addSystem();
}

// TODO try catch le stoi
void RtypeClient::setupUpdateNetworkSystem() {
    ITCPClient *tcpClient = _netManager.createTCPClient(std::stoi(_port));
}

void RtypeClient::setupUpdateEventSystem() {
    //_r.addSystem()
}

void RtypeClient::setupUpdateGraphSystem() {

}
