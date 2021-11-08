/*
** EPITECH PROJECT, 2021
** B-CPP-500-NAN-5-1-babel-romain.gabet
** File description:
** Buffer
*/

#include "Buffer.hpp"

Buffer::Buffer(uint16_t size)
    : _size(size), _usedSize(0), _writeCursor(0), _readCursor(0)
{
    for (auto i = 0; i < size; i++)
        _byteList.push_back(0);
}

bool Buffer::isFull()
{
    return _usedSize == _size;
}

void Buffer::cleanBuffer()
{
    for (auto i = 0; i < _size; i++)
        _byteList[i] = 0;
    _writeCursor = 0;
    _readCursor = 0;
    _usedSize = 0;
}

void Buffer::putInBuffer(uint16_t size, void *data)
{
    uint8_t *castedData;

    //std::cout << "je POUTE " << size << " " << "oui" << std::endl;
    if (!data || size < 1) {
        std::cerr << "ERROR: fillInBuffer() invalid arguments!" << std::endl;
        return;
    }
    _usedSize = ((_usedSize + size) > _size) ? size : _usedSize + size;
    castedData = static_cast<uint8_t *>(data);
    for (auto i = 0; i < size && castedData[i]; i++) {
        _byteList[_writeCursor] = castedData[i];
        _writeCursor = ((_writeCursor + 1) == _size) ? 0 : _writeCursor + 1;
        std::cout << " byte size " << i << std::endl;
    }
}

void Buffer::readFromBuffer(uint16_t size, void *data)
{
    uint8_t *castedData;

    if (!data || size < 1 || !_usedSize) {
        std::cerr << "ERROR: readFromBuffer() invalid arguments!" << std::endl;
        return;
    }
    castedData = static_cast<uint8_t *>(data);
    for (auto i = 0; i < size; i++) {
        castedData[i] = _byteList[_readCursor];
        _readCursor = ((_readCursor + 1) == _size) ? 0 : _readCursor + 1;
        _usedSize--;
        if (!_usedSize)
            break;
    }
}

void Buffer::putInBuffer(uint16_t size, std::vector<uint8_t> &data)
{
    //std::cout << "je POUTE " << size << " . " << data.size() << std::endl;
    if (data.size() < size || size < 1) {
        std::cerr << "ERROR: fillInBuffer() invalid arguments!" << std::endl;
        return;
    }
    //std::cout << data.size() << std::endl;
    _usedSize = ((_usedSize + size) > _size) ? size : _usedSize + size;
    for (auto i = 0; i < size; i++) {
        _byteList[_writeCursor] = data[i];
        _writeCursor = ((_writeCursor + 1) == _size) ? 0 : _writeCursor + 1;
    }
}

void Buffer::readFromBuffer(uint16_t size, std::vector<uint8_t> &data)
{
    //std::cout << "je suis ici" << std::endl;
    if (!_usedSize) {
        std::cerr << "ERROR: readFromBuffer() invalid arguments! (!usedSize)" << std::endl;
        return;
    }
    //std::cout << "je suis la " << data.size() << " | " << _size << " | " << size << std::endl;
    if (data.size() < size || size < 1) {
        std::cerr << "ERROR: readFromBuffer() invalid arguments!" << std::endl;
        return;
    }
    //std::cout << "je suis encore la" << std::endl;
    for (auto i = 0; i < size; i++) {
        data[i] = _byteList[_readCursor];
        _readCursor = ((_readCursor + 1) == _size) ? 0 : _readCursor + 1;
        _usedSize--;
        if (!_usedSize)
            break;
    }
}

uint16_t Buffer::getSize() const
{
    return _size;
}

uint16_t Buffer::getUsedSize() const
{
    return _usedSize;
}

uint16_t Buffer::getWriteCursor() const
{
    return _writeCursor;
}

uint16_t Buffer::getReadCursor() const
{
    return _readCursor;
}