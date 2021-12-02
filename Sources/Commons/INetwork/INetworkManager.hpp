/**
 * \file INetworkManager.hpp
 * 
 * \brief file where INetworkManager class is defined
 * 
 */
#ifndef INETWORKMANAGER_HPP_
    #define INETWORKMANAGER_HPP_

    #include "ITCPClient.hpp"
    #include "ITCPServer.hpp"
    #include "IUDPSocket.hpp"
    #include <vector>
    #include <memory>

    /**
     * \class INetworkManager.hpp
     * 
     * \brief file where interface INetworkManager class is defined
     * 
     */
    class INetworkManager {
        public:

            /**
             * \fn virtual ~INetworkManager() = default
             * 
             * \brief Destroy the INetworkManager object
             */
            virtual ~INetworkManager() = default;

            /**
             * \fn virtual void start() = 0
             * 
             * \brief start connection
             */
            virtual void start() = 0;

            /**
             * \fn virual void stop() = 0
             *
             * \brief stop connection
             */
            virtual void stop() = 0;

            /**
             *
             * \fn virtual ITCPServer *createTCPServer(int port) =  0
             *
             * \brief create a TCP server
             * 
             * \return ITCPServer* 
             */
            virtual ITCPServer *createTCPServer(int port) =  0;

            /**
             * \fn virtual ITCPClient *createTCPClient(int port) = 0
             * 
             * \brief create a TCP client
             * 
             * \return ITCPClient* 
             */
            virtual ITCPClient *createTCPClient(std::string host, int port) = 0;

            /**
             * \fn virtual IUDPSocket *createSocketUDP(int port) = 0
             * 
             * \brief Create a UDP connection
             * 
             * \return UDPSocket* 
             */ 
            virtual IUDPSocket *createSocketUDP(std::string host, int port) = 0;

            /**
             * \fn virtual void deleteSocketUDP(IUDPSocket *socket) = 0
             * 
             * \brief delete a specified UDP connection
             * 
             * \param udp server to delete
             * 
             */
            virtual void deleteSocketUDP(IUDPSocket *socket) = 0;

            /**
             * \fn virtual void deleteTCPServer(ITCPServer *tcp) = 0
             * 
             * \brief delete a specified TCP clie
             * 
             * \param tcp server to delete
             */
            virtual void deleteTCPServer(ITCPServer *tcp) = 0;

            /**
             * \fn virtual void deleteTCPClient(ITCPClient *tcp) = 0;
             * 
             *
             * \brief delete tpc client
             * 
             * \param the tcp client to delete
             */
            virtual void deleteTCPClient(ITCPClient *tcp) = 0;
    };

#endif /* !INETWORKMANAGER_HPP_ */
