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
    #include "Zipper.hpp"
    #include "TCPClient.hpp"
    #include "UDPSocket.hpp"
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
                 * \param client A tcp client 
                 * 
                 * \param socket an UDP socket
                 */
                explicit UpdateNetwork(ITCPClient *client, IUDPSocket *socket);

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
                auto operator()(Registry &r, SparseArray<components::network_s> &networks) -> void;


            private:
                /**
                 * \fn auto LoadingMenuSetupComponentForBackground() -> void
                 *
                 * \brief load the components for the background
                 */
                auto LoadingMenuSetupComponentForBackground() -> void;

                /**
                 * \fn auto LoadingMenuSetupComponentForSwitch() -> void
                 *
                 * \brief load the components for the scene switch
                 */
                auto LoadingMenuSetupComponentForSwitch() -> void;

                /**
                 * \fn auto LoadingMenuSetupComponentForMusic() -> void
                 *
                 * \brief load the components for the music
                 */
                auto LoadingMenuSetupComponentForMusic() -> void;

            private:
                ITCPClient *_tcpClient; /*! A pointer on a tcp client*/
                IUDPSocket *_socket; /*! A pointer on an udp socket */
        };
    }

#endif /* !UPDATENETWORK_HPP_ */
