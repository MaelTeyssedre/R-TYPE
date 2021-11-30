/**
 * \file Room.hpp
 * 
 * \brief file where the Room class is defined 
 * 
 */

#ifndef ROOM_HPP_
    #define ROOM_HPP_

    #include <vector>
    #include "Buffer.hpp"
    #include "Game.hpp"

    namespace rtype {
        /**
         * \class Room
         * 
         * \brief class for Room, a room represent a game
         * 
         */
        class Room {
            public:

                /**
                 * \fn explicit Room() = default
                 * 
                 * \brief Construct a new Room object
                 * 
                 */
                explicit Room() = default;

                /**
                 * \fn explicit Room(size_t id)
                 * 
                 * \brief Construct a new Room object
                 * 
                 * \param id id of te room
                 */
                explicit Room(size_t id);

                /**
                 * \fn explicit Room(Room &)
                 * 
                 * \brief Construct a new Room object from another
                 * 
                 * \param room the room to copy
                 * 
                 */
                explicit Room(Room &room);

                /**
                 * \fn virtuel ~Room() = default
                 * 
                 * \brief Destroy the Room object
                 * 
                 */
                virtual ~Room() = default;

                /**
                 * \fn size_t getId() const
                 * 
                 * \brief Get the Id object
                 * 
                 * \return the id 
                 */
                size_t getId() const;
                
                /**
                 * \fn std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> getRoomBuffer() const
                 * 
                 * \brief Get the Room Buffer object
                 * 
                 * \return std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> 
                 */
                std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> getRoomBuffer() const;

                /**
                 * \fn Room& operator=(Room &room)
                 * 
                 * \brief assignation operator overload
                 * 
                 * \param room room to assign
                 * 
                 * \return assignation reference
                 */
                Room& operator=(Room &room);

                /**
                 * \fn void setRoomBuffer(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer)
                 * 
                 * \brief Set the Room Buffer object
                 * 
                 * \param roomBuffer the pointer the set
                 * 
                 */
                void setRoomBuffer(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer);

                void run();
        
            private:

                std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> _roomBuffers; /*! I/O buffer of all player in the room */
                size_t _id; /*! id of the room */

        };
    }

#endif /* !ROOM_HPP_ */
