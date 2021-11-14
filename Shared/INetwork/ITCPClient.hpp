/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** ITCPClient
*/

#ifndef ITCPCLIENT_HPP_
    #define ITCPCLIENT_HPP_

    #include "IPacket.hpp"

    /**
     * \class ITCPCLient.hpp
     * 
     * \brief file where interface ITCPCLient class is defined
     * 
     */
    class ITCPClient {
        public:

            /**
             * \fn ~ITCPClient() = default
             * 
             * \brief Destroy the ITCPClient object
             * 
             */
            virtual ~ITCPClient() = default;

            /**
             * \fn void send(IPacket &data) = 0
             * 
             * \brief send data
             * 
             * \param data to send
             */
            virtual void send(IPacket &data) = 0;

            /**
             * \fn IPacket &receive() = 0 
             * 
             * \brief receive data
             * 
             * \return return data in packet
             */
            virtual IPacket &receive() = 0;

            /**
             * \fn void connect(std::string &ip, std::uint16_t port) = 0
             * 
             * \brief connect to a socket with specified ip and port
             * 
             * \param ip to connect
             * \param port to connect
             */
            virtual void connect(std::string &ip, std::uint16_t port) = 0;

            /**
             * \fn void disconnect() = 0
             * 
             * \brief disconnect to the socket
             * 
             */
            virtual void disconnect() = 0;
    };

#endif /* !ITCPCLIENT_HPP_ */