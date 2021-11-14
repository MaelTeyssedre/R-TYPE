/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** tcpUser
*/

/**
 * \file tcpUser.hpp
 * 
 * \brief file where tcpUser class is defined
 * 
 */
#ifndef TCPUSER_HPP_
    #define TCPUSER_HPP_

    #include <asio.hpp>
    #include <queue>

    #define MAX_LENGTH 9

    /**
     * \class tcpUser.hpp
     * 
     * \brief file where interface tcpUser class is defined
     * 
     */
    class tcpUser : public std::enable_shared_from_this<tcpUser>
    {
        public: 
            /**
             * \fn explicit tcpUser() = default;
             * 
             * \brief ctor tcpUser
             * 
             */
            explicit tcpUser() = default;

            /**
             * \fn  explicit tcpUser(asio::ip::tcp::socket &&socket)
             * 
             * \brief ctor tcpUser
             * 
             */
            explicit tcpUser(asio::ip::tcp::socket &&socket)  : _socket(std::move(socket)) {};

            /**
             * \fn   virtual ~tcpUser() = default;
             * 
             * \brief dtor tcpUser
             * 
             */
            virtual ~tcpUser() = default;

            /**
             * \fn void start();
             * 
             * \brief start connection
             * 
             */
            void start();

            /**
             * \fn void addToQueue(std::vector<uint8_t> message);
             * 
             * \brief add message to queue to send
             * 
             */
            void addToQueue(std::vector<uint8_t> message);

            /**
             * \fn  void read();
             * 
             * \brief read data from network
             * 
             */
            void read();

            /**
             * \fn void doRead(const std::error_code &ec, size_t bytes);
             * 
             * \brief handle read
             * 
             */
            void doRead(const std::error_code &ec, size_t bytes);

            /**
             * \fn  void write();
             * 
             * \brief write data 
             * 
             */
            void write();

            /**
             * \fn  void doWrite(const std::error_code &ec);
             * 
             * \brief hanlde write
             * 
             */
            void doWrite(const std::error_code &ec);

        private:
            asio::ip::tcp::socket _socket; /*! socket */
            char _data[MAX_LENGTH]; /*! placeholders for packet */
            std::vector<uint8_t> _message; /*! message parsed received  from the client */
            asio::streambuf _input;  /*!  raw data read from the client */
            std::queue<std::vector<uint8_t>> _queue; /*! datas to send */
    };

#endif /* !TCPUSER_HPP_ */