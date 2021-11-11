/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UDPSocket
*/

#ifndef UDPSOCKET_HPP_
#define UDPSOCKET_HPP_

#include "IUDPSocket.hpp"
#include "Packet.hpp"
#include <asio.hpp>

class UDPSocket : public IUDPSocket{
    public:
        UDPSocket();
    //    UDPSocket(asio::io_context &context, std::uint16_t port);
        ~UDPSocket() = default;
        void send(size_t target, IPacket &data) override;
        void send(std::vector<size_t> targets, IPacket &data) override;
        std::vector<uint8_t> receive() override;
        void start() override;
        void stop() override;
        void eject(size_t client) override;
        void startAccept();
        //std::map<size_t, std::shared_ptr<tcpUser>> getUsers() {return (mapUser);};

    private:
        asio::ip::udp::socket _socket;
        asio::io_context _context;
        asio::ip::udp::endpoint _endpoint;
};

#endif /* !UDPSOCKET_HPP_ */