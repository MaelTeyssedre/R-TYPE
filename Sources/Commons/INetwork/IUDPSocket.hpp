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
             */
            virtual ~IUDPSocket() = default;

            /**
             * \fn virtual auto send(IPacket &data) -> void = 0
             * 
             * \brief send data
             * 
             * \param data 
             */
            virtual auto send(IPacket &data) -> void = 0;

            /**
             * \fn virtual auto receive() -> void = 0
             * 
             * \brief receive data
             * 
             * \param data 
             * 
             * \return data received from network
             */
            virtual auto receive() -> void = 0;
    };

#endif /* !IUDPSOCKET_HPP_ */
