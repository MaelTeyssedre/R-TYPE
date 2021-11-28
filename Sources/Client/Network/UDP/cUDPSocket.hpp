/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UDPSocket
*/

#ifndef UDPSOCKET_HPP_
    #define UDPSOCKET_HPP_

    #include <asio.hpp>
    #include "IUDPSocket.hpp"
    #include "Logger.hpp"

    namespace rtype {
        class UDPSocket: public IUDPSocket {
            public:
              /**
               * \fn explicit udpSocket() = default
               * 
               * \brief ctor udp Socket
               */
              explicit UDPSocket() = default;

              /**
               * \fn explicit UDPSocket(asio::io_context &context, std::uint16_t port)
               * 
               * \brief ctor udp client
               * 
               * \param context asio context to use
               * 
               * \param port port to use
               */
              explicit UDPSocket(asio::io_context &context, std::string host, std::string port)
                : _context(context), _socket(_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0)), _logger(std::string{"log.txt"}) {
                  asio::ip::udp::resolver resolver(_context);
                  asio::ip::udp::resolver::query query(asio::ip::udp::v4(), host, port);
                  asio::ip::udp::resolver::iterator iterator = resolver.resolve(query);
                  _endpoint = *iterator;
                };
      
              /**
               * \fn virtual ~UDPSocket() = default;
               * 
               * \brief dtor udp client
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
              void receive() override;

              /**
               * \fn  void handleSend()
               * 
               * \brief handle after receive
               *
               */ 
              void handleSend();

          private:
              asio::io_context &_context; /*! asio context */
              asio::ip::udp::socket _socket; /*! socket to use */
              asio::ip::udp::endpoint _endpoint; /*! endpoint of the user */
              char _data[9]; /*! placeholders for packet */
              std::vector<uint8_t> _message; /*! message parsed received  from the client */
              asio::streambuf _input;  /*!  raw data read from the client */
              Logger _logger; /*! logger */
        };
    }
#endif /* !UDPSOCKET_HPP_ */
