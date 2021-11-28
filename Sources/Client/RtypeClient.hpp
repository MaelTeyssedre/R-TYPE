
#ifndef RTYPECLIENT_HPP_
    #define RTYPECLIENT_HPP_

    #include "Registry.hpp"
    #include "NetworkManager.hpp"
    #include "Components.hpp"
    #include "Systems.hpp"
    #include <iostream>


    namespace rtype {
        class RtypeClient {
            public:
                explicit RtypeClient(std::string port, std::string host);
                virtual ~RtypeClient() = default;
                void run();

            private:
                void _registerComponents();
                void _setupComponents();
                void _setupSystems();

            private:
                void _setupTimeComponent();
                void _setupNetworkComponent();
                void _setupMouseStateComponent();
                void _setupKeyStateComponent();

            private:
                void _setupUpdateTimeSystem();
                void _setupUpdateNetworkSystem();
                void _setupUpdateGraphSystem();
                void _setupUpdatePositionSystem();
                void _setupUpdateDirectionSystem();

            private:
                std::string _port;
                std::string _host;
                Registry _r;
                NetworkManager _netManager;
                ITCPClient *_client;
                IUDPSocket *_socket;
                UpdateNetwork _networkSystem;
                UpdateGraph _graphSystem;
        };
    }

#endif /* !RTYPECLIENT_HPP_ */
