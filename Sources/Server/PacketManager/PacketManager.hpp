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
                explicit PacketManager(std::shared_ptr<std::vector<size_t>> idCreator,  std::shared_ptr<std::vector<std::pair<size_t, size_t>>> idJoiner, std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> roomList);

                /**
                 * \fn virtual  ~PacketManager() = default
                 * 
                 * \brief dtor udp Socket
                 * 
                 */
                virtual ~PacketManager() = default;

                auto managePacket() -> void;

                void manageResponse();

                void sendToClient(PlayerData &player, std::vector<uint8_t> request);                

                auto setBufferI(std::queue<IPacket *> * buffer) -> void;

                auto getRequestsToSend() -> std::vector<IPacket *> &;

            private:

                auto _createRoom(IPacket *packet) -> void;

                auto _joinRoom(IPacket *packet) -> void;

                auto _getRooms(IPacket *packet) -> void;

                auto _setDataRoom() -> std::vector<size_t>;

                auto _getRoomByPlayer(size_t id)->size_t;

                auto _getNbPlayersInRoom(size_t idRoom) -> size_t;

                auto _findPlayer(size_t id) -> bool;

            private:
                std::queue<IPacket*> _packetsIn;
                std::vector<IPacket*> _packetsOut;
                std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> _roomList; /*! vector of player data */
                std::shared_ptr<std::vector<size_t>> _idCreator;
                std::shared_ptr<std::vector<std::pair<size_t, size_t>>> _idJoiner;
                std::vector<std::pair<bool, size_t>> _isCreateSended;
                std::vector<std::pair<bool, size_t>> _isJoinSended;
                std::vector<std::pair<bool, size_t>> _isGetSended;
            };
    }

#endif /* !PACKETMANAGER_HPP_ */
