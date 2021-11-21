/**
 * \file TCPClient.hpp
 * 
 * \brief file where TCPCLient class is defined
 * 
 */

#ifndef TCPCLIENT_HPP_
    #include "ITCPClient.hpp"
    #include "cPacket.hpp"
    #include "Logger.hpp"
    #include <asio.hpp>
    #include "Buffer.hpp"

    #define TCPCLIENT_HPP_

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
            explicit TCPClient() = default;

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
             * \fn void send(IPacket &data) override
             * 
             * \brief send data on the network
             * 
             * \param data data to send
             */
            void send(IPacket &data) override;

            /**
             * \fn void receive() override
             * 
             * \brief receive data from network
             * 
             */
            void receive() override;

            /**
             * \fn void disconnect() override
             * 
             * \brief disconnect from socket
             * 
             */
            void disconnect() override;

            /**
             * \fn void doRead(const std::error_code &ec, size_t bytes)
             * 
             * \brief handle read
             * 
             * \param ec error code returned
             * \param bytes numbers of bytes read
             */
            void doRead(const std::error_code &ec, size_t bytes);

            /**
             * \fn void doWrite(const std::error_code &ec, size_t bytes)
             * 
             * \brief handle write
             * 
             * \param ec error code returned
             * \param bytes numbers of bytes write
             */
            void doWrite(const std::error_code &ec, size_t bytes);

            /**
             * \fn std::shared_ptr<Buffer> getData()
             * 
             * \brief Get the Data object
             * 
             * \return std::shared_ptr<Buffer> 
             */
            std::shared_ptr<Buffer> getData();

        private:
            asio::io_context &_context; /*! asio context */
            asio::ip::tcp::resolver _resolver; /*! asio resolver */
            std::shared_ptr<asio::ip::tcp::socket> _socket; /*! socket connected */
            Logger _logger; /*! logger to log data */
            Packet _packet; /*! packet  */
            std::shared_ptr<Buffer> _buffer; /*! buffer to store input */
            char _reply[9]; /*! store reply */

    };

#endif /* !TCPCLIENT_HPP_ */
