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
    #include <queue>

    /**
     * \namespace rtype
     * 
     * \brief namespace for rtype project
     * 
     */
    namespace rtype {
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
                explicit tcpUser(std::shared_ptr<asio::ip::tcp::socket> client)
                    : _socket(client), _input(new std::vector<uint8_t>) {};

                /**
                 * \fn virtual ~tcpUser() = default;
                 * 
                 * \brief dtor tcpUser
                 * 
                 */
                virtual ~tcpUser() = default;

                /**
                 * \fn auto start() -> void
                 * 
                 * \brief start connection
                 * 
                 */
                auto start() -> void;

                /**
                 * \fn auto addToQueue(std::vector<uint8_t> message) -> void
                 * 
                 * \brief add message to queue to send
                 * 
                 */
                auto addToQueue(std::vector<uint8_t> message) -> void;

                /**
                 * \fn auto read() -> void
                 * 
                 * \brief read data from network
                 * 
                 */
                auto read() -> void;

                /**
                 * \fn auto doRead(const std::error_code &ec, size_t bytes) -> void
                 * 
                 * \brief handle read
                 *
                 * \param ec a reference to the error code
                 *
                 * \param bytes The number of bytes readed
                 * 
                 */
                auto doRead(const std::error_code &ec, size_t bytes) -> void;

                /**
                 * \fn auto write() -> void
                 * 
                 * \brief write data 
                 * 
                 */
                auto write() -> void;

                /**
                 * \fn  auto doWrite(const std::error_code &ec, std::size_t bytes_transfered) -> void
                 * 
                 * \param ec a reference to the error code
                 *
                 * \param bytes_transfered The number of bytes transfered
                 *
                 */
                auto doWrite(const std::error_code &ec, std::size_t bytes_transfered) -> void
                 */
                void doWrite(const std::error_code &ec, std::size_t bytes_transfered);

                /**
                 * \fn  auto getInput() -> std::vector<uint8_t> *
                 * 
                 * \brief get the raw data
                 * 
                 * \return a pointer on a vector which is the data
                 */
                 /**
                 * \fn  auto getSizeInput() -> size_t &
                 * 
                 * \brief get the size of the raw data readed
                 * 
                 * \return a reference on the sizes of the raw data
                 */                auto getInput() -> std::vector<uint8_t> *;

 -> size_t &auto 
                size_t &getSizeInput();

            private:

                std::shared_ptr<asio::ip::tcp::socket> _socket; /*! socket */
                char _data[MAX_LENGTH]; /*! placeholders for packet */
                std::vector<uint8_t> *_input;  /*!  raw data read from the client */
                std::queue<std::vector<uint8_t>> _queue; /*! datas to send */
                size_t _sizeInput;  /*! Size of the raw datat readed */
        };
    }

#endif /* !TCPUSER_HPP_ */
