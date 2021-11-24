
#include "RtypeClient.hpp"

RtypeClient::RtypeClient(std::string host, std::string port)
    : _port(port), _host(host), _r(4)
{
    setupUpdateTimeSystem();
    setupUpdateNetworkSystem();
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
    
    //_r.addSystem();
}

void RtypeClient::setupUpdateNetworkSystem() {
    /*try {
        _tcpClient = _netManager.createTCPClient(std::stoi(_port));
    } catch(std::invalid_argument& e){
        std::cerr << e.what() << std::endl;
    }*/
}

void RtypeClient::setupUpdateEventSystem() {
    //_r.addSystem()
}

void RtypeClient::setupUpdateGraphSystem() {

}
