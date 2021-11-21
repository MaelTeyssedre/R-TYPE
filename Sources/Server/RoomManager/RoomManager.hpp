/**
 * \file RoomManager.hpp
 * 
 * \brief file where RoomManager class is defined
 * 
 */

#ifndef ROOMMANAGER_HPP_
    #define ROOMMANAGER_HPP_

    #include <string>
    #include <thread>
    #include <vector>
    #include <mutex>
    #include <memory>
    #include <array>
    #include <optional>
    #include "Buffer.hpp"
    #include "PlayerData.hpp"

    /**
     * \class RoomManager
     * 
     * @brief Manager of the Rooms
     * 
     */
    class RoomManager {
        public:

            /**
             * \fn explicit RoomManager(std::shared_ptr<std::vector<std::vector<PlayerData>>> roomList, std::shared_ptr<Buffer> bufferIn, std::shared_ptr<Buffer>bufferOut);
             * 
             * \brief Construct a new Room Manager object
             * 
             * \param roomList all the rooms and the player data that contain all needed info to communicate with the player 
             * \param bufferIn Input buffer to get request from PacketManager
             * \param bufferOut Output buffer to send request to PacketManager
             */
            explicit RoomManager(std::shared_ptr<std::vector<std::vector<PlayerData>>> roomList, std::shared_ptr<Buffer> bufferIn, std::shared_ptr<Buffer>bufferOut);

            /**
             * \fn virtual ~RoomManager()
             * 
             * \brief Destroy the Room Manager object
             */
            virtual ~RoomManager();
            
            /**
             * \fn std::string joinRoom(std::string &packet)
             * 
             * \brief put a player inside a room
             * 
             * \param packet packet from the packetManager
             * 
             * \return return the response for the packetManager
             */
            std::string joinRoom(std::string &packet);
            
            /**
             * \fn void manageRoom()
             * 
             * \brief fill the packet list
             * 
             */
            void manageRoom();
            
            /**
             * \fn void redirectRequest(std::vector<std::string> &)
             * 
             * \brief call the proper function according to the packet received
             * 
             * \param packetList list of packet received from the PacktInterpreter
             * 
             */
            void redirectRequest(std::vector<std::string> &packetList);
            
            /**
             * \fn void createRoom(std::string &packet)
             * 
             * \brief Create a Room object
             * 
             * \param packet packet received from the PacketManager
             */
            void createRoom(std::string &packet);
            
            /**
             * \fn void isRoom(size_t id)
             * 
             * \brief execute the Room
             * 
             * \param id id of the room
             */
            void isRoom(size_t id);

        private:

            std::vector<std::thread> _threadList; /*! list of thread for rooms */
            std::shared_ptr<std::vector<std::vector<PlayerData>>> _roomList; /*! list of room who contain list of playerData */
            std::shared_ptr<Buffer> _bufferIn; /*! ptr to input buffer that communicate with PackeManager */
            std::shared_ptr<Buffer> _bufferOut; /*! ptr to output buffer that communicate with PackeManager */
    };

#endif /* !ROOMMANAGER_HPP_ */
