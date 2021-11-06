/*
** EPITECH PROJECT, 2021
** B-CPP-500-NAN-5-1-babel-romain.gabet
** File description:
** Buffer
*/

#ifndef BUFFER_HPP_
#define BUFFER_HPP_

#include <iostream>
#include <vector>
#include <string>


/**
 * @brief Circular Buffer class 
 */
class Buffer {
    public:

        /**
         * @brief Construct a new Buffer object
         * 
         * @param size of buffer
         */
        Buffer(uint16_t size);

        /**
         * @brief Destroy the Buffer object
         */
        ~Buffer() = default;

        /**
         * @brief Boolean function to know if the buffer is full
         * 
         * @return true if the buffer is full
         * @return false if the buffer is not full
         */
        bool isFull();

        /**
         * @brief put data in buffer
         * 
         * @param size : nb of byte to put in the buffer
         * @param data : data to put in the buffer
         */
        void putInBuffer(uint16_t size, void *data);

        /**
         * @brief put data in buffer
         * 
         * @param size : nb of byte to put in the buffer
         * @param data : data to put in the buffer
         */
        void putInBuffer(uint16_t size, std::vector<uint8_t> &data);

        /**
         * @brief read data from buffer
         * 
         * @param size : nb of byte to read
         * @param data : pointer to where store readed data
         */
        void readFromBuffer(uint16_t size, void *data);

        /**
         * @brief read data from buffer
         * 
         * @param size : nb of byte to read
         * @param data : pointer to where store readed data
         */
        void readFromBuffer(uint16_t size, std::vector<uint8_t> &data);

        /**
         * @brief Get the Size of the buffer
         * 
         * @return uint16_t : size of the buffer
         */
        uint16_t getSize() const;

        /**
         * @brief Get the size used in the buffer
         * 
         * @return uint16_t : used size of the buffer
         */
        uint16_t getUsedSize() const;

        /**
         * @brief Get the Write Cursor in the buffer
         * 
         * @return uint16_t : the write cursor
         */
        uint16_t getWriteCursor() const;

        /**
         * @brief Get the Read Cursor in the buffer
         * 
         * @return uint16_t : the read cursor
         */
        uint16_t getReadCursor() const;

        /**
         * @brief delete all data un the buffer
         */
        void cleanBuffer();

    private:
        const uint16_t _size; /** size of the buffer */
        uint16_t _usedSize; /** used size of the buffer */
        uint16_t _writeCursor; /** position where the buffer will write */
        uint16_t _readCursor; /** position where the buffer will read */
        std::vector<uint8_t> _byteList; /** data in the buffer */
};

#endif /* !BUFFER_HPP_ */
