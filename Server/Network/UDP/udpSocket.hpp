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
            UDPSocket(asio::io_context &context, std::uint16_t port)  : _context(context), _socket(context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)) {};
            ~UDPSocket() = default;
            void send(IPacket &data) override;
            std::vector<uint8_t> &receive() override;
            void handleSend();

        private:
            asio::ip::udp::socket _socket;
            asio::io_context &_context;
            asio::ip::udp::endpoint _endpoint;
    };

#endif /* !UDPSOCKET_HPP_ */