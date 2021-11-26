
#ifndef RTYPECLIENT_HPP_
    #define RTYPECLIENT_HPP_

    #include "Registry.hpp"
    #include "NetworkManager.hpp"
    #include "TimeComponent.hpp"
    #include "MouseStateComponent.hpp"
    #include "KeyStateComponent.hpp"
    #include "NetworkComponent.hpp"
    #include "UpdateTime.hpp"
    #include "UpdateNetwork.hpp"
    #include "UpdateGraph.hpp"
    #include <iostream>

    class RtypeClient {
        public:
            explicit RtypeClient(std::string port, std::string host);
            virtual ~RtypeClient() = default;

        public:
            void registerComponents();
            void run();

        public:
            void setupTimeComponent();
            void setupNetworkComponent();
            void setupMouseStateComponent();
            void setupKeyStateComponent();

        public:
            void setupUpdateTimeSystem();
            void setupUpdateNetworkSystem();
            void setupUpdateGraphSystem();

        private:
            std::string _host;
            std::string _port;
            Registry _r;
            NetworkManager _netManager;

    };

#endif /* !RTYPECLIENT_HPP_ */
