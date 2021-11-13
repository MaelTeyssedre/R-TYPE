/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** tcpUser
*/

#ifndef TCPUSER_HPP_
    #define TCPUSER_HPP_

    #include <asio.hpp>
    #include <queue>

    #define MAX_LENGTH 9

    class tcpUser : public std::enable_shared_from_this<tcpUser>
    {
        public: 
            tcpUser() = default;
            tcpUser(asio::ip::tcp::socket &&socket)  : _socket(std::move(socket)) {};
            ~tcpUser() = default;
            void start();
            void addToQueue(std::vector<uint8_t> message);
            void read();
            void doRead(const std::error_code &ec, size_t bytes);
            void write();
            void doWrite(const std::error_code &ec);

        private:
            asio::ip::tcp::socket _socket;
            char _data[MAX_LENGTH]; /** placeholders for packet */
            std::vector<uint8_t> _message; /** message parsed received  from the client */
            asio::streambuf _input;  /**  raw data read from the client */
            std::queue<std::vector<uint8_t>> _queue; /** datas to send */
    };

#endif /* !TCPUSER_HPP_ */