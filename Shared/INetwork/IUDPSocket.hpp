/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IUDPSocket
*/

#ifndef IUDPSOCKET_HPP_
    #define IUDPSOCKET_HPP_

    #include "IPacket.hpp"

    /**
     * \class IUDPSocket IUDPSocket.hpp
     * 
     * \brief file where interface IUDPSocket is defined
     * 
     */
    class IUDPSocket {
        public:

            /**
             * \fn ~IUDPSocket() = default
             * 
             * \brief Destroy the IUDPSocket object
             * 
             */
            virtual ~IUDPSocket() = default;

            /**
             * \fn void send(IPacket &data) = 0
             * 
             * \param data 
             */
            virtual void send(IPacket &data) = 0;

            /**
             * \fn std::vector<uint8_t> &receive() = 0
             * 
             * \brief 
             * 
             * \param data 
             */
            virtual std::vector<uint8_t> &receive() = 0;
    };

#endif /* !IUDPSOCKET_HPP_ */