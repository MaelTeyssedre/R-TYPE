/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UDPSocket
*/

/**
 * \file udpSocket.hpp
 * 
 * \brief file where udpSocket class is defined
 * 
 */
#ifndef UDPSOCKET_HPP_
    #define UDPSOCKET_HPP_

    #include "IUDPSocket.hpp"
    #include "Packet.hpp"
    #include <asio.hpp>

    /**
     * \class udpSocket udpSocket.hpp 
     * 
     * \brief class that containt udp Socket
     */
    class UDPSocket : public IUDPSocket{
        public:
            /**
             * \fn udpSocket() = default
             * 
             * \brief ctor udp Socket
             */
            explicit UDPSocket() = default;

            /**
             * \fn UDPSocket(asio::io_context &context, std::uint16_t port)
             * 
             * \brief ctor TCP server
             * 
             * \param context asio context to use
             * 
             * \param port port to use
             */
            explicit UDPSocket(asio::io_context &context, std::uint16_t port)  : _context(context), _socket(context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)) {};
     
            /**
             * \fn ~UDPSocket() = default;
             * 
             * \brief dtor TCP server
             * 
             */ 
            virtual ~UDPSocket() = default;

            /**
             * \fn void send(IPacket &data)
             * 
             * \brief send data
             * 
             * \param data data to send
             * 
             */ 
            void send(IPacket &data) override;

            /**
             * \fn std::vector<uint8_t> &receive()
             * 
             * \brief receive data from network
             * 
             * \return data received
             * 
             */ 
            std::vector<uint8_t> &receive() override;

            /**
             * \fn  void handleSend()
             * 
             * \brief handle after receive
             *
             */ 
            void handleSend();

        private:
            asio::ip::udp::socket _socket; /*! socket to use */
            asio::io_context &_context; /*! asio context */
            asio::ip::udp::endpoint _endpoint; /*! endpoint of the user */
    };

#endif /* !UDPSOCKET_HPP_ */