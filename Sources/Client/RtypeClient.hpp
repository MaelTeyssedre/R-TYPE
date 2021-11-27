/**
 * \file RtypeClient.hpp
 *
 * \brief file where the r-type-client is defined
 */

#ifndef RTYPECLIENT_HPP_
    #define RTYPECLIENT_HPP_

    #include "Registry.hpp"
    #include "cNetworkManager.hpp"
    #include "TimeComponent.hpp"
    #include "MouseStateComponent.hpp"
    #include "KeyStateComponent.hpp"
    #include "NetworkComponent.hpp"
    #include "UpdateTime.hpp"
    #include "UpdateNetwork.hpp"
    #include "UpdateGraph.hpp"
    #include <iostream>

    /**
     * \class RtypeClient RtypeClient.hpp 
     * 
     * \brief class that contain the RtypeClient
     */
    class RtypeClient {
        public:
            /**
             * \fn explicit RtypeClient(std::string port, std::string host)
             *
             * \brief ctor RtypeClient
             */
            explicit RtypeClient(std::string port, std::string host);

            /**
             * \fn virtual ~RtypeClient() = default
             *
             * \brief dtor RtypeClient
             */
            virtual ~RtypeClient() = default;

        public:
            /**
             * \fn void registerComponents()
             *
             * \brief to register components
             */
            void registerComponents();

            /**
             * \fn void run()
             *
             * \brief run
             */
            void run();

        public:
            /**
             * \fn void setupTimeComponent()
             *
             * \brief setup time component
             */
            void setupTimeComponent();

            /**
             * \fn void setupNetworkComponent()
             *
             * \brief setup network component
             */
            void setupNetworkComponent();

            /**
             * \fn void setupMouseStateComponent()
             *
             * \brief setup mouse state component
             */
            void setupMouseStateComponent();

            /**
             * \fn void setupKeyStateComponent()
             *
             * \brief setup key state component
             */
            void setupKeyStateComponent();

        public:
            /**
             * \fn void setupUpdateTimeSystem()
             *
             * \brief setup update time system
             */
            void setupUpdateTimeSystem();

            /**
             * \fn void setupUpdateNetworkSystem()
             *
             * \brief setup update network system
             */
            void setupUpdateNetworkSystem();
            /**
             * \fn void setupUpdateGraphSystem()
             *
             * \brief setup update graph system
             */
            void setupUpdateGraphSystem();

        private:
            std::string _host; /*! A host */
            std::string _port; /*! A port */
            Registry _r; /*! A registry */
            NetworkManager _netManager; /*! A network manager */

    };

#endif /* !RTYPECLIENT_HPP_ */
