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
             * \fn virtual void send(IPacket &data) = 0
             * 
             * \brief send data
             * 
             * \param data to send
             */
            virtual void send(IPacket &data) = 0;

            /**
             * \fn virtual IPacket &receive() = 0 
             * 
             * \brief receive data
             * 
             * \return return data in packet
             */
            virtual void receive() = 0;

            /**
             * \fn virtual void disconnect() = 0
             * 
             * \brief disconnect to the socket
             * 
             */
            virtual void disconnect() = 0;

            /**
             * \fn std::shared_ptr<Buffer> getData()
             * 
             * \brief Get the Data object
             * 
             * \return std::shared_ptr<Buffer> 
             */
            virtual std::shared_ptr<Buffer> getBuffer() = 0;

            /**
             * \fn virtual bool isConnected() = 0
             * 
             * \brief check if the client is connected
             * 
             * \return true if the client is connected, false otherwise
             */
            virtual bool isConnected() = 0;
    };

#endif /* !ITCPCLIENT_HPP_ */
