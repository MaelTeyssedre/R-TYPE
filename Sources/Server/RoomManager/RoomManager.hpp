/**
 * \file RoomManager.hpp
 * 
 * \brief file where RoomManager class is defined
 * 
 */

#ifndef ROOMMANAGER_HPP_
    #define ROOMMANAGER_HPP_

    #include <thread>
    #include <vector>
    #include <mutex>
    #include "Buffer.hpp"
    #include "PlayerData.hpp"

    namespace rtype {
        /**
         * \class RoomManager
         * 
         * \brief Manager of the Rooms
         * 
         */
        class RoomManager {
            public:

                explicit RoomManager(std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> roomList, std::shared_ptr<std::vector<size_t>> idCreator, std::shared_ptr<std::vector<std::pair<size_t, size_t>>> idJoiner);

                /**
                 * \fn virtual ~RoomManager()
                 * 
                 * \brief Destroy the Room Manager object
                 */
                virtual ~RoomManager() = default;
                
                /**
                 * \fn std::string joinRoom(std::string &packet)
                 * 
                 * \brief put a player inside a room
                 * 
                 * \param packet packet from the packetManager
                 * 
                 * \return return the response for the packetManager
                 */
                auto joinRoom() -> void;
                
                /**
                 * \fn void manageRoom()
                 * 
                 * \brief fill the packet list
                 * 
                 */
                auto manageRoom() -> void;
                
                /**
                 * \fn void createRoom(std::string &packet)
                 * 
                 * \brief Create a Room object
                 * 
                 * \param packet packet received from the PacketManager
                 */
                auto createRoom() -> void;

                auto getIdToCreate() -> size_t;

            private:

                std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> _roomList; /*! list of room who contain list of playerData */
                std::shared_ptr<std::vector<size_t>> _idCreator;
                std::shared_ptr<std::vector<std::pair<size_t, size_t>>> _idJoiner;
        };
    }

#endif /* !ROOMMANAGER_HPP_ */
