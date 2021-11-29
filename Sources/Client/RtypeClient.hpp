/**
 * \file RtypeClient.hpp
 *
 * \brief file where the r-type-client is defined
 */

#ifndef RTYPECLIENT_HPP_
    #define RTYPECLIENT_HPP_

    #include "Registry.hpp"
    #include "NetworkManager.hpp"
    #include "Components.hpp"
    #include "Systems.hpp"
    #include <iostream>
    #include <csignal>


    namespace rtype {
        class RtypeClient {
            public:
                explicit RtypeClient(std::string port, std::string host);
                virtual ~RtypeClient() = default;
                void run();
                static void signalHandler(int signums);
                bool checkStatus();

            private:
                void _registerComponents();
                void _setupComponents();
                void _setupSystems();

            private:
                void _setupTimeComponent();
                void _setupNetworkComponent();
                void _setupMouseStateComponent();
                void _setupKeyStateComponent();
                void _setupCurrentSceneComponent();

            private:
                void _setupUpdateTimeSystem();
                void _setupUpdateNetworkSystem();
                void _setupUpdateGraphSystem();
                void _setupUpdatePositionSystem();
                void _setupUpdateDirectionSystem();
                void _setupUpdateScene();

            private:
                std::string _port;
                std::string _host;
                Registry _r;
                NetworkManager _netManager;
                ITCPClient *_client;
                IUDPSocket *_socket;
                UpdateNetwork _networkSystem;
                UpdateGraph _graphSystem;
                static bool _status;
        };
    }

#endif /* !RTYPECLIENT_HPP_ */
