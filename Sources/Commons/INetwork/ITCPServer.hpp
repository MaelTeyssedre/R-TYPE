/**
 * \file ITCPServer.hpp
 * 
 * \brief file where ITCPServer class is defined
 * 
 */
#ifndef ITCPSERVER_HPP_
    #define ITCPSERVER_HPP_

    #include "IPacket.hpp"
    #include "Buffer.hpp"
    #include <vector>
    #include <queue>

    /**
     * \class ITCPServer.hpp
     * 
     * \brief file where interface ITCPServer.hpp class is defined
     * 
     */
    class ITCPServer {
        public:

            /**
             * \fn  virtual ~ITCPServer() = default
             * 
             * \brief Destroy the ITCPServer object
             */
            virtual ~ITCPServer() = default;

            /**
             * \fn  virtual auto send(std::vector<size_t> targets, IPacket *data) -> void = 0
             * 
             * \brief send data to a list of clients
             * 
             * \param targets 
             * \param data 
             */
            virtual auto send(std::vector<size_t> targets, IPacket *data) -> void = 0;

            /**
             * \fn virtual auto send(IPacket *data) -> void = 0
             * 
             * \brief send data to a client
             * 
             * \param target
             * \param data 
             */
            virtual auto send(IPacket *data) -> void = 0;

            /**
             * \fn virtual auto receive() -> void = 0
             * 
             * \brief receive data
             * 
             * \return return data in packet
             */
            virtual auto receive() -> void = 0;

            /**
             * \fn virtual auto eject(size_t client) -> void = 0
             * 
             * \brief eject client
             * 
             * \param client to eject
             */
            virtual auto eject(size_t client) -> void = 0;

            /**
             * \fn virtual autogetBuffer() -> std::queue<IPacket *> * = 0
             * 
             * \brief get the buffer object
             * 
             * \return A queue of packet get in the buffer
             */
            virtual auto getBuffer() -> std::queue<IPacket *> * = 0;

    };

#endif /* !ITCPSERVER_HPP_ */
