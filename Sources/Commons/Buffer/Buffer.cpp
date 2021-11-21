#include "Buffer.hpp"

Buffer::Buffer(size_t size)
    : _size(size), _usedSize(0), _writeCursor(0), _readCursor(0)
{
    for (size_t i = 0; i < size; i++)
        _byteList.push_back(0);
}

bool Buffer::isFull()
{
    return _usedSize == _size;
}

void Buffer::cleanBuffer()
{
    for (size_t i = 0; i < _size; i++)
        _byteList[i] = 0;
    _writeCursor = 0;
    _readCursor = 0;
    _usedSize = 0;
}

void Buffer::putInBuffer(size_t size, void *data)
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
        std::cout << " byte size " << i << std::endl;
    }
}

void Buffer::readFromBuffer(size_t size, void *data)
{
    uint8_t *castedData;
    if (!data || size < 1 || !_usedSize)
    {
        std::cerr << "ERROR: readFromBuffer() invalid arguments!" << std::endl;
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

void Buffer::putInBuffer(size_t size, std::vector<uint8_t> &data)
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

void Buffer::readFromBuffer(size_t size, std::vector<uint8_t> &data)
{
    if (!_usedSize)
    {
        std::cerr << "ERROR: readFromBuffer() invalid arguments! (!usedSize)" << std::endl;
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

size_t Buffer::getSize() const
{
    return _size;
}

size_t Buffer::getUsedSize() const
{
    return _usedSize;
}

size_t Buffer::getWriteCursor() const
{
    return _writeCursor;
}

size_t Buffer::getReadCursor() const
{
    return _readCursor;
}
