/**
 * \file Buffer.hpp
 * 
 * \brief header for the circular buffer lib
 */

#ifndef BUFFER_HPP_
#define BUFFER_HPP_

#include <vector>
#include <string>


/**
 * \class Buffer
 * 
 * \brief Circular Buffer class 
 */
class Buffer {
    public:
        /**
         * \fn explicit Buffer(size_t size)
         * 
         * \brief Construct a new Buffer object
         * 
         * \param size of buffer
         */
        explicit Buffer(size_t size);

        /**
         * \fn virtual ~Buffer() = default
         * 
         * \brief Destroy the Buffer object
         */
        virtual ~Buffer() = default;

        /**
         * \fn bool isFull()
         * 
         * \brief Boolean function to know if the buffer is full
         * 
         * \return true if the buffer is full, false otherwise
         */
        auto isFull() -> bool;

        /**
         * \fn void putInBuffer(size_t size, void *data)
         * 
         * \brief put data in buffer
         * 
         * \param size : nb of byte to put in the buffer
         * \param data : data to put in the buffer
         */
        auto putInBuffer(size_t size, void *data) -> void;

        /**
         * \fn void putInBuffer(size_t size, std::vector<uint8_t> &data)
         * 
         * \brief put data in buffer
         * 
         * \param size : nb of byte to put in the buffer
         * \param data : data to put in the buffer
         */
        auto putInBuffer(size_t size, std::vector<uint8_t> &data) -> void;

        /**
         * \fn void readFromBuffer(size_t size, void *data)
         * 
         * \brief read data from buffer
         * 
         * \param size : nb of byte to read
         * \param data : pointer to where store readed data
         */
        auto readFromBuffer(size_t size, void *data) -> void;

        /**
         * \fn void readFromBuffer(size_t size, std::vector<uint8_t> &data)
         * 
         * \brief read data from buffer
         * 
         * \param size : nb of byte to read
         * \param data : pointer to where store readed data
         */
        auto readFromBuffer(size_t size, std::vector<uint8_t> &data) -> void;

        /**
         * \fn size_t getSize() const
         * 
         * \brief Get the Size of the buffer
         * 
         * \return size_t : size of the buffer
         */
        auto getSize() -> size_t const;

        /**
         * \fn size_t getUsedSize() const
         * 
         * \brief Get the size used in the buffer
         * 
         * \return size_t : used size of the buffer
         */
        auto getUsedSize() -> size_t const;

        /**
         * \fn size_t getWriteCursor() const
         * 
         * \brief Get the Write Cursor in the buffer
         * 
         * \return size_t : the write cursor
         */
        auto getWriteCursor() -> size_t const;

        /**
         * \fn size_t getReadCursor() const
         * 
         * \brief Get the Read Cursor in the buffer
         * 
         * \return size_t : the read cursor
         */
        auto getReadCursor() -> size_t const;

        /**
         * \fn void cleanBuffer()
         * 
         * \brief delete all data in the buffer
         */
        auto cleanBuffer() -> void;

    private:
        const size_t _size; /** size of the buffer */
        size_t _usedSize; /** used size of the buffer */
        size_t _writeCursor; /** position where the buffer will write */
        size_t _readCursor; /** position where the buffer will read */
        std::vector<uint8_t> _byteList; /** data in the buffer */
};

#endif /* !BUFFER_HPP_ */
