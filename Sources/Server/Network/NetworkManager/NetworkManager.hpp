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
            void start() override;

            /**
             * \fn void stop()
             * 
             * \brief stop connection
             */
            void stop() override;

            /**
             * \fn ITCPServer *createTCPServer(int port)
             * 
             * \brief create tcp server
             * 
             * \param port to use
             * 
             * \return new created tcp server
             */
            ITCPServer *createTCPServer(int port) override;

            /**
             * \fn IUDPSocket *createSocketUDP(int port)
             * 
             * \brief create socket udp
             * 
             * \param port to use
             * 
             * \return new created udp server
             */
            IUDPSocket *createSocketUDP(int port) override;

            /**
             * \fn void deleteTCPServer(ITCPServer *tcp)
             * 
             * \brief delete tcp server
             * 
             * \param tcp server to delete 
             */
            void deleteTCPServer(ITCPServer *tcp) override;

            /**
             * \fn  void deleteSocketUDP(IUDPSocket *socket)
             * 
             * \brief delete udp socket
             * 
             * \param socket to delete
             * 
             */
            void deleteSocketUDP(IUDPSocket *socket) override;

            /**
             * \fn static void startNetworkThread(NetworkManager *netManager)
             * 
             * \brief start network thread
             * 
             * \param network manager
             */
            static void startNetworkThread(NetworkManager *netManager);

            /**
             * \fn ITCPClient *createTCPClient(int port)
             * 
             * \brief create a client TCP
             * 
             * \param port port of the client
             * 
             * \return ITCPClient* pointer to the client
             */
            ITCPClient *createTCPClient(int port);

            /**
             * \fn void deleteTCPClient(ITCPClient *tcp)
             * 
             * \brief delete the TCP client 
             * 
             * \param tcp client to delete
             */
            void deleteTCPClient(ITCPClient *tcp);

        private:

            asio::io_context _context; /*! asio context */
            asio::io_context::work _worker; /*! asio worker */
            std::vector<IUDPSocket *> _udpSockets; /*! vector of udp socket */
            std::vector<ITCPServer *> _tcpServers; /*! vector of tcp server */
            std::thread _thread; /*! thread  of  network*/
    };

#endif /* !NETWORKMANAGER_HPP_ */