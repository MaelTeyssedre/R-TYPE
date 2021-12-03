/**
 * \file PacketManager.hpp
 * 
 * \brief file where PacketManager class is defined
 * 
 */

#ifndef PACKETMANAGER_HPP_
    #define PACKETMANAGER_HPP_

    #include "Packet.hpp"
    #include "Buffer.hpp"
    #include "PlayerData.hpp"
    #include <queue>

    namespace rtype {
        /**
         * \class PacketManager PacketManager.hpp
         * 
         * \brief class that containt PacketManager
         */
        class PacketManager {
            public:

                /**
                 * \fn explicit PacketManager() = default
                 * 
                 * \brief ctor PacketManager
                 */
                explicit PacketManager() = default;

                /**
                 * \fn explicit PacketManager(std::shared_ptr<Buffer> bufferIn,  std::shared_ptr<Buffer> bufferOut)
                 * 
                 * \brief ctor udp Socket
                 * 
                 * \param buffIn buffer input
                 * 
                 * \param buffOut buffer output
                 */
                explicit PacketManager(std::shared_ptr<Buffer> bufferIn,  std::shared_ptr<Buffer> bufferOut);

                /**
                 * \fn virtual  ~PacketManager() = default
                 * 
                 * \brief dtor udp Socket
                 * 
                 */
                virtual ~PacketManager() = default;

                void managePacket(IPacket *packet);

                void createRoom(IPacket *packet);

                void joinRoom(IPacket *packet);

                void sendToClient(PlayerData &player, std::vector<uint8_t> request);


                auto setBufferI(std::queue<IPacket *> * buffer) -> void;

                // * 1 - vide _packet | 2 : return les packets
                auto getRequests() -> std::queue<IPacket *> *;

                auto getRequestsToSend() -> std::vector<IPacket *>;



            private:
                std::queue<IPacket*> *_packets;
                std::vector<IPacket*> *_packetsOut;
                std::shared_ptr<std::vector<std::vector<PlayerData>>> _roomList; /*! vector of player data */
                std::shared_ptr<Buffer> _bufferIn; /*! buffer in */
                std::shared_ptr<Buffer> _bufferOut; /*! buffer out */
        };
    }

#endif /* !PACKETMANAGER_HPP_ */
