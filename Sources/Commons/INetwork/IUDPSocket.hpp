/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IUDPSocket
*/

/**
 * \file IUDPSocket.hpp
 * 
 * \brief file where IUDPSocket class is defined
 * 
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
             * \fn virtual ~IUDPSocket() = default
             * 
             * \brief Destroy the IUDPSocket object
             * 
             */
            virtual ~IUDPSocket() = default;

            /**
             * \fn virtual void send(IPacket &data) = 0
             * 
             * \param data 
             */
            virtual void send(IPacket &data) = 0;

            /**
             * \fn virtual void receive() = 0
             * 
             * \brief 
             * 
             * \param data 
             * 
             * \return data received from network
             * 
             */
            virtual void receive() = 0;
    };

#endif /* !IUDPSOCKET_HPP_ */