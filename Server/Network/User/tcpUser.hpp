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

class tcpUser : public std::enable_shared_from_this<tcpUser>
{
    public: 
        tcpUser() = default;
        tcpUser(asio::ip::tcp::socket &&socket);
        ~tcpUser() = default;
        void start();
        void addToQueue(std::vector<uint8_t> message);
        void read();
        void doRead(const std::error_code &ec, size_t bytes);
        void write();
        void doWrite(const std::error_code &ec, size_t bytes);

    private:
        asio::ip::tcp::socket _socket;
        enum { max_length = 1024}; /** max lenght of one packet */
        char _data[max_length]; /** placeholders for packet */
        std::vector<uint8_t> _message; /** message parsed received  from the client */
        asio::streambuf _input;  /**  raw data read from the client */
        std::queue<std::vector<uint8_t>> _queue; /** datas to send */
};



#endif /* !TCPUSER_HPP_ */