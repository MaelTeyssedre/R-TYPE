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

            /**
             * \fn void managePacket(std::pair<size_t, std::vector<uint8_t>> packet)
             * 
             * \brief manage packet received
             * 
             * \param packet packet to handle
             * 
             */
            void managePacket(std::pair<size_t, std::vector<uint8_t>> packet);

            /**
             * \fn void createRoom(std::pair<size_t, std::vector<uint8_t>> packet)
             * 
             * \brief request for creation room
             * 
             * \param packet packet to handle
             * 
             */
            void createRoom(std::pair<size_t, std::vector<uint8_t>> packet);

            /**
             * \fn     void joinRoom(std::pair<size_t, std::vector<uint8_t>> packet)
             * 
             * \brief request for join room
             * 
             * \param packet packet to handle
             * 
             */
            void joinRoom(std::pair<size_t, std::vector<uint8_t>> packet);

        private:
        
            std::shared_ptr<std::vector<std::vector<PlayerData>>> _roomList; /*! vector of player data */
            std::shared_ptr<Buffer> _bufferIn; /*! buffer in */
            std::shared_ptr<Buffer> _bufferOut; /*! buffer out */
    };

#endif /* !PACKETMANAGER_HPP_ */
