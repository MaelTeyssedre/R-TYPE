/**
 * \file ITCPClient.hpp
 * 
 * \brief file where inteface ITCPClient class is defined
 * 
*/
#ifndef ITCPCLIENT_HPP_
    #define ITCPCLIENT_HPP_

    #include "IPacket.hpp"
    #include "Buffer.hpp"

    /**
     * \class ITCPCLient.hpp
     * 
     * \brief file where interface ITCPCLient class is defined
     * 
     */
    class ITCPClient {
        public:

            /**
             * \fn virtual ~ITCPClient() = default
             * 
             * \brief Destroy the ITCPClient object
             * 
             */
            virtual ~ITCPClient() = default;

            /**
             * \fn virtual auto send(IPacket &data) -> void = 0
             * 
             * \brief send data
             * 
             * \param data to send
             */
            virtual auto send(IPacket &data) -> void = 0;

            /**
             * \fn virtual auto receive() -> void = 0 
             * 
             * \brief receive data
             * 
             * \return return data in packet
             */
            virtual auto receive() -> void = 0;

            /**
             * \fn virtual auto disconnect() -> void = 0
             * 
             * \brief disconnect to the socket
             * 
             */
            virtual auto disconnect() -> void = 0;

            /**
             * \fn virtual auto getBuffer() -> std::shared_ptr<Buffer> = 0
             * 
             * \brief Get the Data object
             * 
             * \return std::shared_ptr<Buffer> 
             */
            virtual auto getBuffer() -> std::shared_ptr<Buffer> = 0;

            /**
             * \fn virtual auto isConnected() -> bool = 0
             * 
             * \brief Check if the client is connected
             * 
             * \return true if the client is connected, false otherwise
             */
            virtual auto isConnected() -> bool = 0;
    };

#endif /* !ITCPCLIENT_HPP_ */
