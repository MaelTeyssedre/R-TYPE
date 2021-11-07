/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** tcpClient
*/

#ifndef TCPCLIENT_HPP_
#define TCPCLIENT_HPP_

#include "ITCPClient.hpp"

class TCPClient : public ITCPClient{
    public:
        TCPClient();
        ~TCPClient() override;
        void send(IPacket &data) override;
        IPacket &receive() override;
        void connect(std::string &ip, std::uint16_t port) override;
        void disconnect() override;

    protected:
    private:
};

#endif /* !TCPCLIENT_HPP_ */
