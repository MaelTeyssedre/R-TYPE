/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPCLient
*/

#ifndef TCPCLIENT_HPP_
    #include "ITCPClient.hpp"
    #include "Packet.hpp"
    #include "Logger.hpp"
    #include <asio.hpp>
    #include "Buffer.hpp"

    #define TCPCLIENT_HPP_

    class TCPClient : public ITCPClient {
        public:
            explicit TCPClient() = default;
            explicit TCPClient(asio::io_context &context, std::shared_ptr<asio::ip::tcp::socket> socket, std::string host, std::string port);
            virtual ~TCPClient() = default;
            void send(IPacket &data) override;
            void receive() override;
            void disconnect() override;
            void doRead(const std::error_code &ec, size_t bytes);
            void doWrite(const std::error_code &ec, size_t bytes);
            std::shared_ptr<Buffer> getData();

        private:
            Logger _logger;
            asio::io_context &_context;
            asio::ip::tcp::resolver _resolver;
            std::shared_ptr<asio::ip::tcp::socket> _socket;
            Packet _packet;
            std::shared_ptr<Buffer> _buffer;
            char _reply[9];

    };

#endif /* !TCPCLIENT_HPP_ */
