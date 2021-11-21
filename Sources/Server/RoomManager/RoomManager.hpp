/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** RoomManager
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

    class RoomManager {
        public:
            explicit RoomManager(std::shared_ptr<std::vector<std::vector<PlayerData>>> roomList, std::shared_ptr<Buffer> bufferIn, std::shared_ptr<Buffer>bufferOut);
            explicit RoomManager(RoomManager &) = default;
            virtual ~RoomManager();
            RoomManager& operator=(RoomManager &) = default;
            std::string joinRoom(std::string &);
            void manageRoom();
            void redirectRequest(std::vector<std::string> &);
            void createRoom(std::string &packet);
            void isRoom(size_t id);
        private:
            std::vector<std::thread> _threadList;
            std::shared_ptr<std::vector<std::vector<PlayerData>>> _roomList;
            std::shared_ptr<Buffer> _bufferIn;
            std::shared_ptr<Buffer> _bufferOut;
    };

#endif /* !ROOMMANAGER_HPP_ */
