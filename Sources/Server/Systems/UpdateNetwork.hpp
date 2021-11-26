
#ifndef UPDATENETWORK_HPP_
    #define UPDATENETWORK_HPP_

    #include "Registry.hpp"
    #include "NetworkComponent.hpp"
    #include "Constants.hpp"
    #include "tcpServer.hpp"
    #include "udpSocket.hpp"
    #include "Buffer.hpp"

    class UpdateNetwork {
        public:
            explicit UpdateNetwork() = default;
            explicit UpdateNetwork(ITCPServer *server, IUDPSocket *socket);
            virtual ~UpdateNetwork() = default;
            void operator()(Registry &r, SparseArray<components::network_s> &networks);

        private:
            ITCPServer *_tcpServer;
            IUDPSocket *_socket;
    };

#endif /* !UPDATENETWORK_HPP_ */
