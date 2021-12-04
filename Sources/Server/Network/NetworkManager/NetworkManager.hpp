/**
 * \file NetworkManager.hpp
 * 
 * \brief file where NetworkManger class is defined
 * 
 */

#ifndef NETWORKMANAGER_HPP_
    #define NETWORKMANAGER_HPP_

    #include "INetworkManager.hpp"
    #include "udpSocket.hpp"
    #include "tcpServer.hpp"
    #include <asio.hpp>
    #include <thread>

    namespace rtype {
        /**
         * \class NetworkManager NetworkManager.hpp
         * 
         * \brief class that contain methode to manage network
         */
        class NetworkManager : public INetworkManager{
            public:

                /**
                 * \fn explicit NetworkManager()
                 * 
                 * \brief ctor networkManager
                 */
                explicit NetworkManager()
                    : _context(), _worker(_context), _udpSockets(), _tcpServers(), _thread() {}

                /**
                 * \fn virtual ~NetworkManager()
                 * 
                 * \brief dtor NetworkManager
                 */
                virtual ~NetworkManager() = default;

                /**
                 * \fn void start()
                 * 
                 * \brief start connection
                 */
                auto start() override -> void;

                /**
                 * \fn void stop()
                 * 
                 * \brief stop connection
                 */
                auto stop() override -> void;

                /**
                 * \fn ITCPServer *createTCPServer(int port)
                 * 
                 * \brief create tcp server
                 * 
                 * \param port to use
                 * 
                 * \return new created tcp server
                 */
                auto createTCPServer(int port) override -> ITCPServer *;

                /**
                 * \fn IUDPSocket *createSocketUDP(int port)
                 * 
                 * \brief create socket udp
                 * 
                 * \param port to use
                 * 
                 * \return new created udp server
                 */
                auto createSocketUDP(std::string host, int port) override -> IUDPSocket *;

                /**
                 * \fn void deleteTCPServer(ITCPServer *tcp)
                 * 
                 * \brief delete tcp server
                 * 
                 * \param tcp server to delete 
                 */
                auto deleteTCPServer(ITCPServer *tcp) override -> void;

                /**
                 * \fn  void deleteSocketUDP(IUDPSocket *socket)
                 * 
                 * \brief delete udp socket
                 * 
                 * \param socket to delete
                 * 
                 */
                auto deleteSocketUDP(IUDPSocket *socket) override -> void;

                /**
                 * \fn static void startNetworkThread(NetworkManager *netManager)
                 * 
                 * \brief start network thread
                 * 
                 * \param network manager
                 */
                static auto startNetworkThread(NetworkManager *netManager) -> void;

                /**
                 * \fn ITCPClient *createTCPClient(int port)
                 * 
                 * \brief create a client TCP
                 * 
                 * \param port port of the client
                 * 
                 * \return ITCPClient* pointer to the client
                 */
                auto createTCPClient(std::string host, int port) -> ITCPClient *;

                /**
                 * \fn void deleteTCPClient(ITCPClient *tcp)
                 * 
                 * \brief delete the TCP client 
                 * 
                 * \param tcp client to delete
                 */
                auto deleteTCPClient(ITCPClient *tcp) -> void;

            private:

                asio::io_context _context; /*! asio context */
                asio::io_context::work _worker; /*! asio worker */
                std::vector<IUDPSocket *> _udpSockets; /*! vector of udp socket */
                std::vector<ITCPServer *> _tcpServers; /*! vector of tcp server */
                std::thread _thread; /*! thread  of  network*/
        };
    }

#endif /* !NETWORKMANAGER_HPP_ */
