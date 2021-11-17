/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPCLient
*/

#ifndef TCPCLIENT_HPP_
    #include "ITCPClient.hpp"
    #include "Packet.hpp"
    #include <asio.hpp>
    #define TCPCLIENT_HPP_

    class TCPClient : public ITCPClient {
        public:
            explicit TCPClient() = default;
            explicit TCPClient(asio::io_context &context, std::shared_ptr<asio::ip::tcp::socket> socket, std::string host, std::string port);
            virtual ~TCPClient() = default;
            void send(IPacket &data);
            IPacket &receive();
            void connect(std::string &ip, std::uint16_t port) {};
            void disconnect();
        private:
            asio::io_context &_context;
            asio::ip::tcp::resolver _resolver;
            std::shared_ptr<asio::ip::tcp::socket> _socket;
            char _reply[9];

    };

#endif /* !TCPCLIENT_HPP_ */
