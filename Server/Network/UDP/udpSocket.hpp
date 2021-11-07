/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UDPSocket
*/

#ifndef UDPSOCKET_HPP_
#define UDPSOCKET_HPP_

#include "IUDPSocket.hpp"
#include "IPacket.hpp"

class UDPSocket : public IUDPSocket{
    public:
        UDPSocket();
        ~UDPSocket();
        void send(IPacket &data) override;
        void send(std::vector<size_t>, IPacket &data) override;
        void sendToAll(IPacket &data) override;
        IPacket &receiver() override;
        void start(std::uint16_t port) override;
        void stop() override;
        
    protected:
    private:
};

#endif /* !UDPSOCKET_HPP_ */