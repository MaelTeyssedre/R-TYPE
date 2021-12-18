/**
/**
 * \file TCPClient.hpp
 * 
 * \brief file where TCPCLient class is defined
 * 
 */

#ifndef TCPCLIENT_HPP_
    #include "ITCPClient.hpp"
    #include "Packet.hpp"
    #include "Logger.hpp"
    #include <asio.hpp>
    #include "Buffer.hpp"
    #include "Constants.hpp"

    #define TCPCLIENT_HPP_

    namespace rtype {
        /**
         * \class TCPClient TCPCLient.hpp
         * 
         * \brief class that contain methode to manage tcp client 
         * 
         */
        class TCPClient : public ITCPClient {
            public:
                /**
                 * \fn explicit TCPCLient()
                 * 
                 * \brief ctor TCPClient
                 * 
                 */
                TCPClient() = delete;

                /**
                 * \brief Construct a new TCPClient object
                 * 
                 * \param context asio context
                 * \param socket asio socket 
                 * \param host host to connect
                 * \param port port to connect
                 */
                explicit TCPClient(asio::io_context &context, std::shared_ptr<asio::ip::tcp::socket> socket, std::string host, std::string port);

                /**
                 * \brief Destroy the TCPClient object
                 */
                virtual ~TCPClient() = default;

                /**
                 * \fn auto send(IPacket &data) -> void override
                 * 
                 * \brief send data on the network
                 * 
                 * \param data data to send
                 */
                auto send(IPacket &data) -> void override;

                /**
                 * \fn auto receive() -> void override
                 * 
                 * \brief receive data from network
                 * 
                 */
                auto receive() -> void override;

                /**
                 * \fn auto disconnect() -> void override
                 * 
                 * \brief disconnect from socket
                 * 
                 */
                auto disconnect() -> void override;

                /**
                 * \fn auto doRead(const std::error_code &ec, size_t bytes) -> void
                 * 
                 * \brief handle read
                 * 
                 * \param ec error code returned
                 *
                 * \param bytes numbers of bytes read
                 */
                auto doRead(const std::error_code &ec, size_t bytes) -> void;

                /**
                 * \fn auto doWrite(const std::error_code &ec, size_t bytes) -> void
                 * 
                 * \brief handle write
                 * 
                 * \param ec error code returned
                 * \param bytes numbers of bytes write
                 */
                auto doWrite(const std::error_code &ec, size_t bytes) -> void;

                /**
                 * \fn auto getBuffer() -> std::shared_ptr<Buffer> override
                 * 
                 * \brief Get the Data object
                 * 
                 * \return std::shared_ptr<Buffer> 
                 */
                auto getBuffer() -> std::shared_ptr<Buffer> override;

                /**
                 * \fn auto isConnected() -> bool override
                 * 
                 * \brief Check if the player is connected
                 * 
                 * \return true if the player is connectd
                 */
                auto isConnected() -> bool override;

            private:
                asio::io_context &_context; /*! asio context */
                asio::ip::tcp::resolver _resolver; /*! asio resolver */
                std::shared_ptr<asio::ip::tcp::socket> _socket; /*! socket connected */
                Logger _logger; /*! logger to log data */
                IPacket *_packet; /*! packet  */
                std::shared_ptr<Buffer> _buffer; /*! buffer to store input */
                char _reply[8192]; /*! store reply */
                bool _isConnected;
                asio::io_context::work _worker; /*! asio worker */
        };
    }

#endif /* !TCPCLIENT_HPP_ */
