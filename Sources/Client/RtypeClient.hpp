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
                auto run() -> void;
                static auto signalHandler(int signums) -> void;
                auto checkStatus() -> bool;

            private:
                auto _registerComponents() -> void;
                auto _setupComponents() -> void;
                auto _setupSystems() -> void;

            private:
                auto _setupTimeComponent() -> void;
                auto _setupNetworkComponent() -> void;
                auto _setupMouseStateComponent() -> void;
                auto _setupKeyStateComponent() -> void;
                auto _setupCurrentSceneComponent() -> void;

            private:
                auto _setupUpdateTimeSystem() -> void;
                auto _setupUpdateNetworkSystem() -> void;
                auto _setupUpdateGraphSystem() -> void;
                auto _setupUpdatePositionSystem() -> void;
                auto _setupUpdateDirectionSystem() -> void;
                auto _setupUpdateScene() -> void;
                auto _setupUpdateClickable() -> void;

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
