/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** NetworkManager
*/

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

            
            ITCPClient *createTCPClient(int port);

            void deleteTCPClient(ITCPClient *tcp);

            IUDPSocket *createSocketUDP(int port) override;

            void deleteSocketUDP(IUDPSocket *udp) override;



            ITCPServer *createTCPServer(int port) override {(void)port; return nullptr;};
            void deleteTCPServer(ITCPServer *tcp) override  {(void)tcp;};

        private:
            asio::io_context _context; /*! asio context */
            asio::io_context::work *_worker; /*! asio worker */
            std::vector<ITCPClient *> _tcpClients; /*! vector of tcp server */
            std::vector<IUDPSocket *> _udpSockets; /*! vector of tcp server */
            std::thread _thread; /*! thread  of  network*/
    };

#endif /* !NETWORKMANAGER_HPP_ */