
#ifndef UPDATENETWORK_HPP_
    #define UPDATENETWORK_HPP_

    #include "Registry.hpp"
    #include "NetworkComponent.hpp"
    #include "Constants.hpp"
    #include "Zipper.hpp"
    #include "cTCPClient.hpp"
    #include "cUDPSocket.hpp"
    #include "Buffer.hpp"

    namespace rtype {
        class UpdateNetwork {
            public:
                explicit UpdateNetwork() = default;
                explicit UpdateNetwork(ITCPClient *client, IUDPSocket *socket);
                virtual ~UpdateNetwork() = default;
                void operator()(Registry &r, SparseArray<components::network_s> &networks);

            private:
                ITCPClient *_tcpClient;
                IUDPSocket *_socket;
        };
    }

#endif /* !UPDATENETWORK_HPP_ */