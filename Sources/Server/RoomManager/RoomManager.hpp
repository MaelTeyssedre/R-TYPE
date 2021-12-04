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

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {
        /**
         * \class RoomManager
         * 
         * \brief Manager of the Rooms
         * 
         */
        class RoomManager {
            public:

                /**
                 * \fn explicit RoomManager(std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> roomList, std::shared_ptr<std::vector<size_t>> idCreator, std::shared_ptr<std::vector<std::pair<size_t, size_t>>> idJoiner)
                 * 
                 * \brief Room manager ctor
                 *
                 * \param roomlist A list of room with information on the players who joins each room
                 *
                 * \param idCreator A pointer on a vector of id of players who have created room
                 *
                 * \param idJoiner A pointer on a vector of id of players who have joined room
                 */
                explicit RoomManager(std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> roomList, std::shared_ptr<std::vector<size_t>> idCreator, std::shared_ptr<std::vector<std::pair<size_t, size_t>>> idJoiner);

                /**
                 * \fn virtual ~RoomManager()
                 * 
                 * \brief Destroy the Room Manager object
                 */
                virtual ~RoomManager() = default;
                
                /**
                 * \fn auto joinRoom() -> void
                 * 
                 * \brief put a player inside a room
                 * 
                 */
                auto joinRoom() -> void;
                
                /**
                 * \fn auto manageRoom() -> void
                 * 
                 * \brief fill the packet list
                 * 
                 */
                auto manageRoom() -> void;
                
                /**
                 * \fn auto createRoom() -> void
                 * 
                 * \brief Create a Room object
                 *
                 */
                auto createRoom() -> void;

                /**
                 * \fn auto getIdToCreate() -> size_t
                 * 
                 * \brief Get an id to create a room
                 *
                 * \return the getted id
                 */
                auto getIdToCreate() -> size_t;

            private:

                std::shared_ptr<std::vector<std::pair<std::vector<PlayerData>, size_t>>> _roomList; /*! list of room who contain list of playerData */
                std::shared_ptr<std::vector<size_t>> _idCreator; /*! A vector of player that have created room */
                std::shared_ptr<std::vector<std::pair<size_t, size_t>>> _idJoiner; /*! A vector of player that have joined room */
        };
    }

#endif /* !ROOMMANAGER_HPP_ */
