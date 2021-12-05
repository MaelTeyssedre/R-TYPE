/**
 * \file Packet.hpp
 * 
 * \brief file where Packet class is defined
 * 
 */

#ifndef TCPSERVER_HPP_
    #define TCPSERVER_HPP_

    #include "Packet.hpp"
    #include "tcpUser.hpp"
    #include "ITCPServer.hpp"
    #include "Buffer.hpp"
    #include <queue>

    /**
     * \namespace rtype
     * 
     * \brief global namespace for the rtype project
     * 
     */
    namespace rtype {
        /**
         * \class Packet Packet.hpp 
         * 
         * \brief class that containt tcp server
         */
        class TCPServer : public ITCPServer {

            public:

                /**
                 * \fn explicitTCPServer() = default
                 * 
                 * \brief ctor TCP server
                 */
                explicit TCPServer() = default;

                /**
                 * \fn explicit TCPServer(asio::io_context &context, std::uint16_t port)
                 * 
                 * \brief ctor TCP server
                 * 
                 * \param asio context
                 * 
                 * \param port to use
                 * 
                 */
                explicit TCPServer(asio::io_context &context, std::uint16_t port);

                /**
                 * \fn virtual ~TCPServer() = default
                 * 
                 * \brief dtor TCP server
                 */
                virtual ~TCPServer() = default;

                /**
                 * \fn  auto send(IPacket *data) -> void override
                 * 
                 * \brief send data to a user
                 * 
                 * \param data data to send
                 */
                auto send(IPacket *data) -> void override;
                
                /**
                 * \fn auto send(std::vector<size_t> targets, IPacket *data) -> void override
                 * 
                 * \brief send data to a user list
                 * 
                 * \param target list of user to send data
                 * 
                 * \param data data to send
                 */
                auto send(std::vector<size_t> targets, IPacket *data) -> void override;
                
                /**
                 * \fn auto receive() -> void override
                 * 
                 * \brief receive data
                 * 
                 */
                auto receive() -> void override;
                
                /**
                 * \fn auto eject(size_t client) -> void override
                 * 
                 * \brief eject client
                 * 
                 * \param client client to eject
                 * 
                 */
                auto eject(size_t client) -> void override;

                /**
                 * \fn auto startAccept() -> void
                 * 
                 * \brief start accepting client
                 * 
                 */ 
                auto startAccept() -> void;

                /**
                 * \fn auto getUsers() -> std::vector<std::shared_ptr<tcpUser>>
                 * 
                 * \brief get the user list
                 * 
                 * \return A vector of pointer on user
                 */
                auto getUsers() -> std::vector<std::shared_ptr<tcpUser>>;

            
//                std::queue<std::shared_ptr<rtype::Packet>> getRequest();

                /**
                 * \fn auto getBuffer() -> std::queue<IPacket *> * override
                 * 
                 * \brief get the buffer
                 * 
                 * \return A queue of pointer on data
                 */
                auto getBuffer() -> std::queue<IPacket *> * override;

            private:
            
                asio::io_context &_context; /*! asio context */
                asio::ip::tcp::acceptor _acceptor; /*! asio acceptor */
                std::vector<std::shared_ptr<tcpUser>> _mapUser; /*! vector of id and user */
                int _nbUsers; /*! nb of users */
                std::queue<IPacket *> _buffers; /*! buffer to store input */
        };
    }

#endif /* !TCPSERVER_HPP_ */
