/**
 * \file UpdateNetwork.hpp
 *
 * \brief file where the update network system is defined
 */
#ifndef UPDATENETWORK_HPP_
    #define UPDATENETWORK_HPP_

    #include "Registry.hpp"
    #include "RequestComponent.hpp"
    #include "Constants.hpp"
    #include "tcpServer.hpp"
    #include "udpSocket.hpp"
    #include "Buffer.hpp"

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {
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
                 * \brief ctor UpdateNetwork
                 */
                explicit UpdateNetwork() = default;

                /**
                 * \fn explicit UpdateNetwork() = default
                 *
                 * \brief ctor UpdateNetwork
                 * 
                 * \param server A tcp server 
                 * 
                 * \param socket an UDP socket
                 */
                explicit UpdateNetwork(ITCPServer *server, IUDPSocket *socket);

                /**
                 * \fn virtual ~UpdateNetwork() = default
                 *
                 * \brief dtor UpdateNetwork
                 */
                virtual ~UpdateNetwork() = default;

                /**
                 * \fn auto operator()(Registry &r, SparseArray<components::network_s> &networks) -> void
                 *
                 * \brief operator to be used by the ECS
                 * 
                 * \param r A reference to the registry
                 * 
                 * \param networks reference to a sparseArray of network components
                 */
                auto operator()(Registry &r, SparseArray<components::request_s> &networks) -> void;

            private:
                ITCPServer *_tcpServer; /*! A tcp server*/
                IUDPSocket *_socket; /*! An udp socket */
        };
    }

#endif /* !UPDATENETWORK_HPP_ */
