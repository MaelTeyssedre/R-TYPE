#include "Buffer.hpp"
#include <iostream>

Buffer::Buffer(size_t size)
    : _size(size), _usedSize(0), _writeCursor(0), _readCursor(0)
{
    for (size_t i = 0; i < size; i++)
        _byteList.push_back(0);
}

auto Buffer::isFull() -> bool
{
    return _usedSize == _size;
}

auto Buffer::cleanBuffer() -> void
{
    for (size_t i = 0; i < _size; i++)
        _byteList[i] = 0;
    _writeCursor = 0;
    _readCursor = 0;
    _usedSize = 0;
}

auto Buffer::putInBuffer(size_t size, void *data) -> void
{
    uint8_t *castedData;
    if (!data || size < 1)
    {
        std::cerr << "ERROR: fillInBuffer() invalid arguments!" << std::endl;
        return;
    }
    _usedSize = ((_usedSize + size) > _size) ? size : _usedSize + size;
    castedData = static_cast<uint8_t *>(data);
    for (size_t i = 0; i < size && castedData[i]; i++)
    {
        _byteList[_writeCursor] = castedData[i];
        _writeCursor = ((_writeCursor + 1) == _size) ? 0 : _writeCursor + 1;
    }
}

auto Buffer::readFromBuffer(size_t size, void *data) -> void
{
    uint8_t *castedData;
    if (!data || size < 1 || !_usedSize)
    {
        return;
    }
    castedData = static_cast<uint8_t *>(data);
    for (size_t i = 0; i < size; i++)
    {
        castedData[i] = _byteList[_readCursor];
        _readCursor = ((_readCursor + 1) == _size) ? 0 : _readCursor + 1;
        _usedSize--;
        if (!_usedSize)
            break;
    }
}

auto Buffer::putInBuffer(size_t size, std::vector<uint8_t> &data) -> void
{
    if (data.size() < size || size < 1)
    {
        std::cerr << "ERROR: fillInBuffer() invalid arguments!" << std::endl;
        return;
    }
    _usedSize = ((_usedSize + size) > _size) ? size : _usedSize + size;
    for (size_t i = 0; i < size; i++)
    {
        _byteList[_writeCursor] = data[i];
        _writeCursor = ((_writeCursor + 1) == _size) ? 0 : _writeCursor + 1;
    }
}

auto Buffer::readFromBuffer(size_t size, std::vector<uint8_t> &data) -> void
{
    if (!_usedSize)
    {
        return;
    }
    if (data.size() < size || size < 1)
    {
        std::cerr << "ERROR: readFromBuffer() invalid arguments!" << std::endl;
        return;
    }
    for (size_t i = 0; i < size; i++)
    {
        data[i] = _byteList[_readCursor];
        _readCursor = ((_readCursor + 1) == _size) ? 0 : _readCursor + 1;
        _usedSize--;
        if (!_usedSize)
            break;
    }
}

auto Buffer::getSize() -> size_t const
{
    return _size;
}

auto Buffer::getUsedSize() -> size_t const
{
    return _usedSize;
}

auto Buffer::getWriteCursor() -> size_t const
{
    return _writeCursor;
}

auto Buffer::getReadCursor() -> size_t const
{
    return _readCursor;
}
