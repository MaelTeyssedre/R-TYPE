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
        ~TCPServer() override;
        void send(IPacket &data) override;
        void send(std::vector<size_t> targets, IPacket &data) override;
        void sendToAll(IPacket &data) override;
       // IPacket &receive() override;
        void start() override;
        void stop() override;
        void eject(size_t client) override;
        asio::ip::tcp::socket getUserSocket(int id);

    protected:
    private:
        void doRead();
        void doWrite();
        void accept();
        std::map<int, tcpUser> _users;
};

#endif /* !TCPSERVER_HPP_ */