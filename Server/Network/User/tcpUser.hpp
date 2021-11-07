/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** tcpUser
*/

#ifndef TCPUSER_HPP_
#define TCPUSER_HPP_

#include <asio.hpp>

class tcpUser
{
    public: 
        tcpUser();
        ~tcpUser() = default;
        std::shared_ptr<asio::ip::tcp::socket> getSocket();

    private:
        std::shared_ptr<asio::ip::tcp::socket> _socket;
};



#endif /* !TCPUSER_HPP_ */