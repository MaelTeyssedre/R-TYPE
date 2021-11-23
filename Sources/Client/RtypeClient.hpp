/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** RtypeClient
*/

#ifndef RTYPECLIENT_HPP_
#define RTYPECLIENT_HPP_

#include "Registry.hpp"
#include "cNetworkManager.hpp"
#include "iostream"

class RtypeClient {
    public:
        explicit RtypeClient(std::string port, std::string host);
        virtual ~RtypeClient() = default;

    private:
        std::unique_ptr<Registry> r;
        NetworkManager netManager;
};

#endif /* !RTYPECLIENT_HPP_ */
