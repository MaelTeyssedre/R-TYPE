
#ifndef UPDATENETWORK_HPP_
    #define UPDATENETWORK_HPP_

    #include "Registry.hpp"
    #include "NetworkComponent.hpp"
    #include "Constants.hpp"
    #include "cTCPClient.hpp"
    #include "Buffer.hpp"

    class UpdateNetwork {
        public:
            UpdateNetwork() = default;
            UpdateNetwork(ITCPClient *client);
            ~UpdateNetwork();
            void operator()(Registry &r, SparseArray<components::network_t> &networks);

        protected:
        private:
            ITCPClient *_tcpClient;
    };

#endif /* !UPDATENETWORK_HPP_ */
