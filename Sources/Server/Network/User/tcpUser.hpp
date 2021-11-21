/**
 * \file tcpUser.hpp
 * 
 * \brief file where tcpUser class is defined
 * 
 */

#ifndef TCPUSER_HPP_
    #define TCPUSER_HPP_

    #ifndef MAX_LENGTH
        #define MAX_LENGTH 9
    #endif

    #include <asio.hpp>
    #include <memory>
    #include <iostream>
    #include <queue>

    /**
     * \class tcpUser.hpp
     * 
     * \brief file where interface tcpUser class is defined
     * 
     */
    class tcpUser
    {
        public: 
            /**
             * \fn explicit tcpUser() = default;
             * 
             * \brief ctor tcpUser
             * 
             */
            explicit tcpUser() = delete;

            /**
             * \fn tcpUser(const tcpUser &other) = delete
             * 
             * \brief Construct a new tcp User object
             * 
             * \param other to copy
             */
            tcpUser(const tcpUser &other) = delete;

            /**
             * \fn tcpUser& operator=(const tcpUser &rhs) = delete
             * 
             * \brief assignment operator
             * 
             * \param rhs to assign
             * 
             * \return tcpUser& ref to the assigned
             */
            tcpUser& operator=(const tcpUser &rhs) = delete;

            /**
             * \fn  explicit tcpUser(asio::ip::tcp::socket &&socket)
             * 
             * \brief ctor tcpUser
             * 
             */
            explicit tcpUser(std::shared_ptr<asio::ip::tcp::socket> client)  : _socket(client) {std::cout << "tcpUser ctor" << std::endl;};

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
            void doWrite(const std::error_code &ec, std::size_t bytes_transfered);

            /**
             * \fn uint8_t *getInput()
             * 
             * \brief Get the Input object
             * 
             * \return uint8_t* the input
             */
            uint8_t *getInput();

        private:

            std::shared_ptr<asio::ip::tcp::socket> _socket; /*! socket */
            char _data[MAX_LENGTH]; /*! placeholders for packet */
            std::vector<uint8_t> _message; /*! message parsed received  from the client */
            uint8_t _input[MAX_LENGTH];  /*!  raw data read from the client */
            std::queue<std::vector<uint8_t>> _queue; /*! datas to send */
    };

#endif /* !TCPUSER_HPP_ */
