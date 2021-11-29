/**
 * \file UpdateNetwork.hpp
 *
 * \brief file where the update network system is defined
 */

#ifndef UPDATENETWORK_HPP_
    #define UPDATENETWORK_HPP_

    #include "Registry.hpp"
    #include "NetworkComponent.hpp"
    #include "Constants.hpp"
    #include "cTCPClient.hpp"
    #include "cUDPSocket.hpp"
    #include "Buffer.hpp"

    /**
     * \class UpdateNetwork UpdateNetwork.hpp 
     * 
     * \brief class that contain the system UpdateNetwork
     */
    class UpdateNetwork {
        public:
            /**
             * \fn explicit UpdateNetwork() = default
             *
             * \brief default ctor UpdateNetwork
             */
            explicit UpdateNetwork() = default;

            /**
             * \fn explicit UpdateNetwork() = default
             *
             * \brief ctor UpdateNetwork
             * 
             * \param client the client whose network is updated
             * 
             * \param socket The used UDP socket
             */
            explicit UpdateNetwork(ITCPClient *client, IUDPSocket *socket);
            /**
             * \fn virtual ~UpdateNetwork() = default
             *
             * \brief dtor UpdateNetwork
             */
            virtual ~UpdateNetwork() = default;

            /**
             * \fn void operator()(Registry &r, SparseArray<components::network_t> &networks)
             *
             * \brief To be used by the ECS
             * 
             * \param r A reference to the registry
             * 
             * \param networks a reference to a sparceArray of network components
             */
            void operator()(Registry &r, SparseArray<components::network_t> &networks);

        private:
            ITCPClient *_tcpClient; /*! The tcp client */
            IUDPSocket *_socket; /*! Socket for UDP connections*/
    };

#endif /* !UPDATENETWORK_HPP_ */
