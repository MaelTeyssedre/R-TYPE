/**
 * \file NetworkManager.hpp
 * 
 * \brief file where NetworkManger class is defined
 * 
 */
#ifndef NETWORKMANAGER_HPP_
    #define NETWORKMANAGER_HPP_

    #include "INetworkManager.hpp"
    #include "cTCPClient.hpp"
    #include "cUDPSocket.hpp"
    #include <asio.hpp>
    #include <thread>

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
             * \fn void start()
             * 
             * \brief start connection
             * 
             */
            void start() override;

            /**
             * \fn void stop()
             * 
             * \brief stop connection
             * 
             */
            void stop() override;


            /**
             * \fn static void startNetworkThread(NetworkManager *netManager)
             * 
             * \brief start network thread
             * 
             * \param network manager
             * 
             */
            static void startNetworkThread(NetworkManager *netManager);

            /**
             * \fn ITCPClient *createTCPClient(int port)
             * 
             * \brief create a TCP client 
             * 
             * \param port port that will be used for the communication
             *  
             * \return ITCPClient* the client
             */
            ITCPClient *createTCPClient(int port);

            /**
             * \fn void deleteTCPClient(ITCPClient *tcp)
             * 
             * \brief delete a TCP client 
             * 
             * \param tcp client to delete
             */
            void deleteTCPClient(ITCPClient *tcp);

            /**
             * \fn IUDPSocket *createSocketUDP(int port) override
             * 
             * \brief create a socket UDP
             * 
             * \param port port to open the socket
             * 
             * \return IUDPSocket* created socket
             */
            IUDPSocket *createSocketUDP(int port) override;

            /**
             * \fn void deleteSocketUDP(IUDPSocket *udp) override
             * 
             * \brief delete a socket UDP
             * 
             * \param udp the socket tu delete 
             */
            void deleteSocketUDP(IUDPSocket *udp) override;

            /**
             * \fn ITCPServer *createTCPServer(int port) override
             * 
             * \brief create a TCP server 
             * 
             * \param port the server will listen on this port
             * 
             * \return ITCPServer* the created server 
             */
            ITCPServer *createTCPServer(int port) override;

            /**
             * \fn void deleteTCPServer(ITCPServer *tcp) override
             * 
             * \brief delete a tcp server
             * 
             * @param tcp the server to delete
             */
            void deleteTCPServer(ITCPServer *tcp) override;

        private:
            asio::io_context _context; /*! asio context */
            asio::io_context::work *_worker; /*! asio worker */
            std::vector<ITCPClient *> _tcpClients; /*! vector of tcp server */
            std::vector<IUDPSocket *> _udpSockets; /*! vector of tcp server */
            std::thread _thread; /*! thread  of  network*/
    };

#endif /* !NETWORKMANAGER_HPP_ */
