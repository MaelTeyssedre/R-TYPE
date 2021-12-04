/**
 * \file Room.hpp
 * 
 * \brief file where the Room class is defined 
 * 
 */

#ifndef ROOM_HPP_
    #define ROOM_HPP_


    #include "Buffer.hpp"
    #include "Registry.hpp"
    #include "JsonWrapper.hpp"
    #include "NetworkComponent.hpp"
    #include "PlayerData.hpp"
    #include <thread>
    #include <vector>
    #include <memory>

    /**
     * \namespace rtype
     * 
     * \brief namespace for rtype project
     * 
     */
    namespace rtype {
        
        /**
         * \class Room Room.hpp
         * 
         * \brief class that containt Room
         */
        class Room {
            public:
                /**
                 * \fn explicit Room(std::vector<PlayerData> *players)
                 * 
                 * \brief Construct a room
                 * 
                 */
                explicit Room(std::vector<PlayerData> *players);
                
                /**
                 * \fn virtual ~Room() = default
                 * 
                 * \brief Destroy the room
                 * 
                 */
                virtual ~Room() = default;

            private:
            
                /**
                 * \fn static auto _runThread(std::vector<PlayerData>* players) -> void
                 * 
                 * \brief Run a thread
                 * 
                 * \param players Vector of player data inside the thread
                 */
                static auto _runThread(std::vector<PlayerData>* players) -> void;
            private:
                std::unique_ptr<std::thread> _threadPtr; /*! pointer on the room thread */
        };
    }

#endif /* !ROOM_HPP_ */
