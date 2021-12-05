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


    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {
        /**
         * \class RtypeClient RtypeClient.hpp 
         * 
         * \brief class that contain the r-type client
         */
        class RtypeClient {
            public:
                /**
                 * \fn explicit RtypeClient(std::string port, std::string host)
                 *
                 * \brief an R-Type ctor
                 * 
                 * \param port the port where the client is connected
                 * 
                 * \param host the host of the client
                 */
                explicit RtypeClient(std::string port, std::string host);

                /**
                 * \fn virtual ~RtypeClient() = default
                 *
                 * \brief dtor RtypeClient
                 */
                virtual ~RtypeClient() = default;

                /**
                 * \fn auto run() -> void
                 *
                 * \brief run the r-type client system
                 */
                auto run() -> void;

                /**
                 * \fn static auto signalHandler(int signums) -> void
                 *
                 * \brief catch signal and apply corresponding callback
                 * 
                 * \param signums the signums of the sigal catch
                 */
                static auto signalHandler(int signums) -> void;

                /**
                 * \fn auto checkStatus() -> bool
                 *
                 * \brief check the status of the client
                 * 
                 * \return true if the client is ok
                 */
                auto checkStatus() -> bool;

            private:
                /**
                 * \fn auto _registerComponents() -> void
                 *
                 * \brief register components on the client
                 */
                auto _registerComponents() -> void;

                /**
                 * \fn auto _setupComponents() -> void
                 *
                 * \brief setup components on the client
                 */
                auto _setupComponents() -> void;

                /**
                 * \fn auto _setupSystems() -> void
                 *
                 * \brief setup system on the client
                 */
                auto _setupSystems() -> void;

            private:
                /**
                 * \fn auto _setupTimeComponent() -> void
                 *
                 * \brief setup time components on the client
                 */
                auto _setupTimeComponent() -> void;

                /**
                 * \fn auto _setupNetworkComponent() -> void
                 *
                 * \brief setup Network components on the client
                 */
                auto _setupNetworkComponent() -> void;

                /**
                 * \fn auto _setupMouseStateComponent() -> void
                 *
                 * \brief setup MouseState components on the client
                 */
                auto _setupMouseStateComponent() -> void;

                /**
                 * \fn auto _setupKeyStateComponent() -> void
                 *
                 * \brief setup KeyState components on the client
                 */
                auto _setupKeyStateComponent() -> void;

                /**
                 * \fn auto _setupCurrentSceneComponent() -> void
                 *
                 * \brief setup CurrentScene components on the client
                 */
                auto _setupCurrentSceneComponent() -> void;

            private:

                /**
                 * \fn auto _setupUpdateTimeSystem() -> void
                 *
                 * \brief setup UpdateTime system on the client
                 */
                auto _setupUpdateTimeSystem() -> void;

                /**
                 * \fn auto _setupUpdateTimeSystem() -> void
                 *
                 * \brief setup UpdateNetwork system on the client
                 */
                auto _setupUpdateNetworkSystem() -> void;

                /**
                 * \fn auto _setupUpdateGraphSystem() -> void
                 *
                 * \brief setup UpdateGraph system on the client
                 */
                auto _setupUpdateGraphSystem() -> void;

                /**
                 * \fn auto _setupUpdatePositionSystem() -> void
                 *
                 * \brief setup UpdatePosition system on the client
                 */
                auto _setupUpdatePositionSystem() -> void;

                /**
                 * \fn auto _setupUpdateDirectionSystem() -> void
                 *
                 * \brief setup UpdateDirection system on the client
                 */
                auto _setupUpdateDirectionSystem() -> void;

                /**
                 * \fn auto _setupUpdateScene() -> void
                 *
                 * \brief setup the scene updater on the client
                 */
                auto _setupUpdateScene() -> void;

                /**
                 * \fn auto _setupUpdateClickable() -> void
                 *
                 * \brief setup the clickable component updater on the client
                 */
                auto _setupUpdateClickable() -> void;

            private:
                std::string _port; /*! Port which the client is connected to*/
                std::string _host; /*! Host the client is using */
                Registry _r; /*! Registry used for stocking component */
                NetworkManager _netManager; /*! The network manager */
                ITCPClient *_client; /*! A TCP client */
                IUDPSocket *_socket; /*! An UDP socket */
                UpdateNetwork _networkSystem; /*! A UpdateNetwork system */
                UpdateGraph _graphSystem; /*! A graphical system */
                static bool _status; /*! The client status */
        };
    }

#endif /* !RTYPECLIENT_HPP_ */
