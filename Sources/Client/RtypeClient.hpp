
#ifndef RTYPECLIENT_HPP_
    #define RTYPECLIENT_HPP_

    #include "Registry.hpp"
    #include "cNetworkManager.hpp"
    #include "TimeComponent.hpp"
    #include "MouseStateComponent.hpp"
    #include "KeyStateComponent.hpp"
    #include "NetworkComponent.hpp"
    #include "UpdateTime.hpp"
    #include <iostream>

    class RtypeClient {
        public:
            explicit RtypeClient(std::string port, std::string host);
            virtual ~RtypeClient() = default;

        public:
            void run();

        public:
            components::myTime_t setupTimeComponent();
            components::network_t setupNetworkComponent();
            components::mouseState_t setupMouseStateComponent();
            components::keyState_t setupKeyStateComponent();

        public:
            void setupUpdateTimeSystem();
            void setupUpdateNetworkSystem();
            void setupUpdateGraphSystem();
            void setupUpdateEventSystem();

        private:
            std::string _host;
            std::string _port;
            Registry _r;
            NetworkManager _netManager;

    };

#endif /* !RTYPECLIENT_HPP_ */
