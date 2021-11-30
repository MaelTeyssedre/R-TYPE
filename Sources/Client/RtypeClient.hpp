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
                 * \fn void run()
                 *
                 * \brief run the r-type client system
                 */
                void run();

                /**
                 * \fn static void signalHandler(int signums)
                 *
                 * \brief catch signal and apply corresponding callback
                 * 
                 * \param signums the signums of the sigal catch
                 */
                static void signalHandler(int signums);

                /**
                 * \fn bool checkStatus()
                 *
                 * \brief check the status of the client
                 * 
                 * \return true if the client is ok
                 */
                bool checkStatus();

            private:
                /**
                 * \fn void _registerComponents()
                 *
                 * \brief register components on the client
                 */
                void _registerComponents();

                /**
                 * \fn void _setupComponents()
                 *
                 * \brief setup components on the client
                 */
                void _setupComponents();

                /**
                 * \fn void _setupSystems()
                 *
                 * \brief setup system on the client
                 */
                void _setupSystems();

            private:
                /**
                 * \fn void _setupTimeComponent()
                 *
                 * \brief setup time components on the client
                 */
                void _setupTimeComponent();

                /**
                 * \fn void _setupNetworkComponent()
                 *
                 * \brief setup Network components on the client
                 */
                void _setupNetworkComponent();

                /**
                 * \fn void _setupMouseStateComponent()
                 *
                 * \brief setup MouseState components on the client
                 */
                void _setupMouseStateComponent();

                /**
                 * \fn void _setupCurrentSceneComponent()
                 *
                 * \brief setup CurrentScene components on the client
                 */
                void _setupKeyStateComponent();

                /**
                 * \fn void _setupKeyStateComponent()
                 *
                 * \brief setup KeyState components on the client
                 */
                void _setupCurrentSceneComponent();

            private:
                /**
                 * \fn void _setupUpdateTimeSystems()
                 *
                 * \brief setup UpdateTime system on the client
                 */
                void _setupUpdateTimeSystem();

                /**
                 * \fn void _setupUpdateNetworkSystems()
                 *
                 * \brief setup UpdateNetwork system on the client
                 */
                void _setupUpdateNetworkSystem();

                /**
                 * \fn void _setupUpdateGraphSystems()
                 *
                 * \brief setup UpdateGraph system on the client
                 */
                void _setupUpdateGraphSystem();

                /**
                 * \fn void _setupUpdatePositionSystems()
                 *
                 * \brief setup UpdatePosition system on the client
                 */
                void _setupUpdatePositionSystem();

                /**
                 * \fn void _setupUpdateDirectionSystems()
                 *
                 * \brief setup UpdateDirection system on the client
                 */
                void _setupUpdateDirectionSystem();

                /**
                 * \fn void _setupUpdateScene()
                 *
                 * \brief setup the scene updater on the client
                 */
                void _setupUpdateScene();

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
