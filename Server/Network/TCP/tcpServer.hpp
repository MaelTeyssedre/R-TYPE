/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPServer
*/

#ifndef TCPSERVER_HPP_
#define TCPSERVER_HPP_

#include "Packet.hpp"
#include "tcpUser.hpp"
#include "ITCPServer.hpp"
#include <map>


class TCPServer : public ITCPServer {
    public:
        TCPServer();
        TCPServer(asio::io_context &context, std::uint16_t port);
        ~TCPServer() = default;
        void send(size_t target, IPacket &data) override;
        void send(std::vector<size_t> targets, IPacket &data) override;
        std::vector<uint8_t> receive() override;
        void start() override;
        void stop() override;
        void eject(size_t client) override;
        void startAccept();
        std::map<size_t, std::shared_ptr<tcpUser>> getUsers() {return (mapUser);};

    private:

        void handleAccept(std::shared_ptr<tcpUser> newUser);

        asio::io_context &_context;
        asio::ip::tcp::acceptor _acceptor;
        std::map<size_t, std::shared_ptr<tcpUser>> mapUser;
        int _nbUsers;
};

#endif /* !TCPSERVER_HPP_ */

