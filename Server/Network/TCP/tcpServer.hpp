/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPServer
*/


/**
 * \file Packet.hpp
 * 
 * \brief file where Packet class is defined
 * 
 */
#ifndef TCPSERVER_HPP_
    #define TCPSERVER_HPP_

    #include "Packet.hpp"
    #include "tcpUser.hpp"
    #include "ITCPServer.hpp"
    #include <map>


    /**
     * \class Packet Packet.hpp 
     * 
     * \brief class that containt tcp server
     */
    class TCPServer : public ITCPServer {
        public:
            /**
             * \fn explicitTCPServer() = default
             * 
             * \brief ctor TCP server
             */
            explicit TCPServer() = default;

            /**
             * \fn explicit TCPServer(asio::io_context &context, std::uint16_t port)
             * 
             * \brief ctor TCP server
             * 
             * \param asio context
             * 
             * \param port to use
             * 
             */
            explicit TCPServer(asio::io_context &context, std::uint16_t port);

            /**
             * \fn virtual ~TCPServer() = default
             * 
             * \brief dtor TCP server
             */
            virtual ~TCPServer() = default;

            /**
             * \fn  void send(size_t target, IPacket &data)
             * 
             * \brief send data to a user
             * 
             * \param target to send data
             * 
             * \param data data to send
             */
            void send(size_t target, IPacket &data) override;
            
            /**
             * \fn void send(std::vector<size_t> targets, IPacket &data)
             * 
             * \brief send data to a user list
             * 
             * \param target list of user to send data
             * 
             * \param data data to send
             */
            void send(std::vector<size_t> targets, IPacket &data) override;
            
            /**
             * \fn std::vector<uint8_t> receive()
             * 
             * \brief receive data
             * 
             * \return data received
             * 
             */
            std::vector<uint8_t> receive() override;
            
            /**
             * \fn  void eject(size_t client)
             * 
             * \brief eject client
             * 
             * \param client client to eject
             * 
             */
            void eject(size_t client) override;

            /**
             * \fn void startAccept();
             * 
             * \brief start accepting client
             * 
             */ 
            void startAccept();

            /**
             * \fn  std::map<size_t, std::shared_ptr<tcpUser>> getUsers()
             * 
             * \brief return list of client
             * 
             * \return list of client
             * 
             */ 
            std::map<size_t, std::shared_ptr<tcpUser>> getUsers();

        private:
            asio::io_context &_context; /*! asio context */
            asio::ip::tcp::acceptor _acceptor; /*! asio acceptor */
            std::map<size_t, std::shared_ptr<tcpUser>> _mapUser; /*! map of id and user */
            int _nbUsers; /*! nb of users */
    };

#endif /* !TCPSERVER_HPP_ */

