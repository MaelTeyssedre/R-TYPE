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
             * \fn virtual auto start() -> void = 0
             * 
             * \brief start connection
             */
            virtual auto start() -> void = 0;

            /**
             * \fn virtual auto stop() -> void = 0
             *
             * \brief stop connection
             */
            virtual auto stop() -> void = 0;

            /**
             *
             * \fn virtual auto createTCPServer(int port) -> ITCPServer * = 0
             *
             * \brief create a TCP server
             * 
             * \return ITCPServer* 
             */
            virtual auto createTCPServer(int port) -> ITCPServer * = 0;

            /**
             * \fn virtual auto createTCPClient(std::string host, int port) -> ITCPClient * = 0
             * 
             * \brief create a TCP client
             * 
             * \return ITCPClient* 
             */
            virtual auto createTCPClient(std::string host, int port) -> ITCPClient * = 0;

            /**
             * \fn virtual auto createSocketUDP(std::string host, int port) -> IUDPSocket * = 0
             * 
             * \brief Create a UDP connection
             * 
             * \return UDPSocket* 
             */ 
            virtual auto createSocketUDP(std::string host, int port) -> IUDPSocket * = 0;

            /**
             * \fn virtual auto deleteSocketUDP(IUDPSocket *socket) -> void = 0
             * 
             * \brief delete a specified UDP connection
             * 
             * \param udp server to delete
             * 
             */
            virtual auto deleteSocketUDP(IUDPSocket *socket) -> void = 0;

            /**
             * \fn virtual auto deleteTCPServer(ITCPServer *tcp) -> void = 0
             * 
             * \brief delete a specified TCP clie
             * 
             * \param tcp server to delete
             */
            virtual auto deleteTCPServer(ITCPServer *tcp) -> void = 0;

            /**
             * \fn virtual auto deleteTCPClient(ITCPClient *tcp) -> void = 0;
             * 
             *
             * \brief delete tpc client
             * 
             * \param the tcp client to delete
             */
            virtual auto deleteTCPClient(ITCPClient *tcp) -> void = 0;
    };

#endif /* !INETWORKMANAGER_HPP_ */
