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
             * \fn  virtual void send(std::vector<size_t> targets, IPacket &data) = 0
             * 
             * \brief send data to a list of clients
             * 
             * \param targets 
             * \param data 
             */
            virtual void send(std::vector<size_t> targets, IPacket &data) = 0;

            /**
             * \fn  virtual void send(size_t target, IPacket &data) = 0
             * 
             * \brief send data to a client
             * 
             * \param target
             * \param data 
             */
            virtual void send(size_t target, IPacket &data) = 0;

            /**
             * \fn virtual std::vector<uint8_t> receive() = 0
             * 
             * \brief receive data
             * 
             * \return return data in packet
             */
            virtual void receive() = 0;

            /**
             * \fn  virtual void eject(size_t client) = 0
             * 
             * \brief eject client
             * 
             * \param client to eject
             */
            virtual void eject(size_t client) = 0;

            virtual std::queue<IPacket *> getBuffer() = 0;

    };

#endif /* !ITCPSERVER_HPP_ */
