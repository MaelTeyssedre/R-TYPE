#include "TCPClient.hpp"

rtype::TCPClient::TCPClient(asio::io_context &context, std::shared_ptr<asio::ip::tcp::socket> socket, std::string host, std::string port)
    : _context(context), _resolver(context), _socket(socket), _logger("log.txt"), _buffer(new Buffer(BUF_SIZE)) , _isConnected(false), _worker(context)
{
    std::string str = "Client connected to host: ";
    asio::error_code ec;
    asio::connect(*_socket, _resolver.resolve(host, port), ec);
    if (ec) {
        std::cerr << "cant find a connection" << std::endl;
        _logger.logln("Cant find a connection");
        return;
    }
    _isConnected = true;
    str.append(host);
    str.append(", and port: ");
    str.append(port);
    _logger.logln(str);
    
}

void rtype::TCPClient::receive()
{
    _socket->async_read_some(asio::buffer(_reply), std::bind(&rtype::TCPClient::doRead, this, std::placeholders::_1, std::placeholders::_2));
}

void rtype::TCPClient::doRead(const std::error_code &ec, size_t bytes)
{
    std::string str;
    if (!ec)
    {
        str = "receive: ";
        str.append(std::to_string(bytes));
        str.append("bytes");
        _logger.logln(str);
        _buffer->putInBuffer(bytes, _reply);
        receive();
    }
    else
        std::cerr << ec.message() << std::endl;
}

void rtype::TCPClient::send(IPacket &packet)
{
    std::cout << "in send" << std::endl;
    asio::async_write(*_socket, asio::buffer(packet.unpack()), std::bind(&rtype::TCPClient::doWrite, this, std::placeholders::_1, std::placeholders::_2));

}

void rtype::TCPClient::doWrite(const std::error_code &ec, size_t bytes)
{
    std::string str = "Send: ";
    if (!ec)
    {
        str.append(std::to_string(bytes));
        str.append("bytes");
        _logger.logln(str);
    }
    else
        std::cerr << ec.message() << std::endl;
}

std::shared_ptr<Buffer> rtype::TCPClient::getBuffer()
{
    return _buffer;
}

void rtype::TCPClient::disconnect()
{
    _socket->close();
    _logger.logln(std::string{"Client disconnect"});
}


bool rtype::TCPClient::isConnected()
{
    return (_isConnected);
}
