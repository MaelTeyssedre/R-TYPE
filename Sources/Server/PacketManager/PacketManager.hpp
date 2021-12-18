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

    /**
     * \namespace rtype
     * 
     * \brief namespace for rtype project
     * 
     */
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
                 * \fn explicit PacketManager(std::shared_ptr<std::vector<size_t>> idCreator,  std::shared_ptr<std::vector<std::pair<size_t, size_t>>> idJoiner, std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> roomList)
                 * 
                 * \brief ctor packet manager
                 * 
                 * \param idCreator A pointer on a vector of players who have created room
                 * 
                 * \param idJoiner A pointer on a vector of players who have joined room
                 *
                 * \param roomList A vector of room which contain players data
                 */
                explicit PacketManager(std::shared_ptr<std::vector<size_t>> idCreator,  std::shared_ptr<std::vector<std::pair<size_t, size_t>>> idJoiner, std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> roomList);

                /**
                 * \fn virtual ~PacketManager() = default
                 * 
                 * \brief dtor udp Socket
                 * 
                 */
                virtual ~PacketManager() = default;

                /**
                 * \fn auto managePacket() -> void
                 * 
                 * \brief manage the packet that have been get
                 * 
                 */
                auto managePacket() -> void;

                /**
                 * \fn auto manageResponse() -> void
                 * 
                 * \brief manage the response according to the received packets
                 * 
                 */
                auto manageResponse() -> void;


                auto sendToPlayer(PlayerData &player, std::vector<uint8_t>) -> void;

                /**
                 * \fn auto setBufferI(std::queue<IPacket *> * buffer) -> void
                 * 
                 * \brief set buffer input
                 *
                 * \param buffer A pointer to a buffer which is a queue of IPacket
                 * 
                 */
                auto setBufferI(std::queue<IPacket *> * buffer) -> void;

                /**
                 * \fn auto getRequestsToSend() -> std::vector<IPacket *> &
                 * 
                 * \brief get the list of request you want to send
                 *
                 * \return A reference to a list of IPacket which are the request we want to send
                 * 
                 */
                auto getRequestsToSend() -> std::vector<IPacket *> &;

            private:

                /**
                 * \fn auto _createRoom(IPacket *packet) -> void
                 * 
                 * \brief create a room
                 *
                 * \param packet A pointer to a IPacket which contain the information to create the room
                 * 
                 */
                auto _createRoom(IPacket *packet) -> void;

                /**
                 * \fn auto _joinRoom(IPacket *packet) -> void
                 * 
                 * \brief join a room
                 *
                 * \param packet A pointer to a IPacket which contain the information to join the room
                 * 
                 */
                auto _joinRoom(IPacket *packet) -> void;

                /**
                 * \fn auto _getRooms(IPacket *packet) -> void
                 * 
                 * \brief get a room
                 *
                 * \param packet A pointer to a IPacket which contain the information of the room
                 * 
                 */
                auto _getRooms(IPacket *packet) -> void;

                // ! What?
                auto _setDataRoom() -> std::vector<size_t>;

                /**
                 * \fn auto _getRoomByPlayer(size_t id) -> size_t
                 * 
                 * \brief Get the room id of where the player is
                 *
                 * \param id id of the player
                 * 
                 * \return id of the room the player is
                 * 
                 */
                auto _getRoomByPlayer(size_t id) -> size_t;

                auto _getPlayersInRoom(IPacket *packet) -> void;

                auto _roomExist(size_t id) -> bool;
                /**
                 * \fn auto _getNbPlayersInRoom(size_t idRoom) -> size_t
                 * 
                 * \brief Get number of player in room
                 *
                 * \param idRoom id of the room
                 * 
                 * \return number of players in the room
                 * 
                 */
                auto _getNbPlayersInRoom(size_t idRoom) -> size_t;

                auto _findPlayer(size_t id) -> PlayerData*;


            private:
                std::queue<IPacket*> _packetsIn; /*! A queue of pointer of packet getted */
                std::vector<IPacket*> _packetsOut; /*! A vector of packet sended */
                std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> _roomList; /*! vector of room which contain players data */
                std::shared_ptr<std::vector<size_t>> _idCreator; /*! A pointer on a vector of players who have created room */
                std::shared_ptr<std::vector<std::pair<size_t, size_t>>> _idJoiner; /*! A pointer on a vector of players who have joined room */
                std::vector<std::pair<bool, size_t>> _isCreateSended; /*! A vector which contain a list of room creation request received */
                std::vector<std::pair<bool, size_t>> _isJoinSended; /*! A vector which contain a list of room join request received */
                std::vector<std::pair<bool, size_t>> _isGetSended; /*! A vector which contain a list of asked room request received */
                std::vector<std::pair<bool, size_t>> _isGetPlayerSended; /*! A vector which contain a list of asked room request received */
            };
    }

#endif /* !PACKETMANAGER_HPP_ */
