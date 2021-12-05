/**
 * \file NetworkManager.hpp
 * 
 * \brief file where NetworkManger class is defined
 * 
 */
#ifndef NETWORKMANAGER_HPP_
    #define NETWORKMANAGER_HPP_

    #include "INetworkManager.hpp"
    #include "TCPClient.hpp"
    #include "UDPSocket.hpp"
    #include <asio.hpp>
    #include <thread>

    namespace rtype {
        /**
         * \class NetworkManager NetworkManager.hpp
         * 
         * \brief class that contain methode to manage network
         * 
         */
        class NetworkManager : public INetworkManager {
            public:
                /**
                 * \fn explicit NetworkManager()
                 * 
                 * \brief ctor networkManager
                 */
                explicit NetworkManager() : _context(), _worker(), _tcpClients(), _thread() {};

                /**
                 * \fn virtual ~NetworkManager()
                 * 
                 * \brief dtor NetworkManager
                 * 
                 */
                virtual ~NetworkManager() = default;

                /**
                 * \fn auto start() -> void override
                 * 
                 * \brief start connection
                 * 
                 */
                auto start() -> void override;

                /**
                 * \fn auto stop() -> void override
                 * 
                 * \brief stop connection
                 * 
                 */
                auto stop() -> void override;


                /**
                 * \fn static auto startNetworkThread(NetworkManager *netManager) -> void;
                 * 
                 * \brief start network thread
                 * 
                 * \param netManager A pointe on a network manager object
                 * 
                 */
                static auto startNetworkThread(NetworkManager *netManager) -> void;

                /**
                 * \fn auto createTCPClient(std::string host, int port) ->ITCPClient * override
                 * 
                 * \brief create a TCP client 
                 * 
                 * \param port port that will be used for the communication
                 *  
                 * \return ITCPClient* A pointer on the client
                 */
                auto createTCPClient(std::string host, int port) ->ITCPClient * override;

                /**
                 * \fn auto deleteTCPClient(ITCPClient *tcp) -> void override
                 * 
                 * \brief delete a TCP client 
                 * 
                 * \param tcp client to delete
                 */
                auto deleteTCPClient(ITCPClient *tcp) -> void override;

                /**
                 * \fn auto createSocketUDP(std::string host, int port) -> IUDPSocket * override
                 * 
                 * \brief create a socket UDP
                 * 
                 * \param port port to open the socket
                 * 
                 * \return IUDPSocket* created socket
                 */
                auto createSocketUDP(std::string host, int port) -> IUDPSocket * override;

                /**
                 * \fn auto deleteSocketUDP(IUDPSocket *udp) -> void override
                 * 
                 * \brief delete a socket UDP
                 * 
                 * \param udp the socket tu delete 
                 */
                auto deleteSocketUDP(IUDPSocket *udp) -> void override;

                /**
                 * \fn auto createTCPServer(int port) -> ITCPServer * override
                 * 
                 * \brief create a TCP server 
                 * 
                 * \param port the server will listen on this port
                 * 
                 * \return ITCPServer* the created server 
                 */
                auto createTCPServer(int port) -> ITCPServer * override;

                /**
                 * \fn auto deleteTCPServer(ITCPServer *tcp) -> void override
                 * 
                 * \brief delete a tcp server
                 * 
                 * \param tcp the server to delete
                 */
                auto deleteTCPServer(ITCPServer *tcp) -> void override;

            private:
                asio::io_context _context; /*! asio context */
                asio::io_context::work *_worker; /*! asio worker */
                std::vector<ITCPClient *> _tcpClients; /*! vector of tcp server */
                std::vector<IUDPSocket *> _udpSockets; /*! vector of tcp server */
                std::thread _thread; /*! thread  of  network*/
        };
    }

#endif /* !NETWORKMANAGER_HPP_ */
