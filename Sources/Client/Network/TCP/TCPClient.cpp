#include "TCPClient.hpp"

rtype::TCPClient::TCPClient(asio::io_context& context, std::shared_ptr<asio::ip::tcp::socket> socket, std::string host, std::string port)
	: _context(context), _resolver(context), _socket(socket), _logger("log.txt"), _buffer(new Buffer(BUF_SIZE)), _isConnected(false), _worker(context)
{
	std::memset(_reply, 42, 8192);
	std::string str = "Client connected to host: ";
	asio::error_code ec;
	asio::ip::tcp::endpoint endpoint;
	endpoint = asio::connect(*_socket, _resolver.resolve(host, port), ec);
	if (ec)
	{
		std::cerr << "cant find a connection" << std::endl;
		_logger.logln("Cant find a connection");
		return;
	}
	_isConnected = true;
	str.append(host);
	str.append(", and port: ");
	str.append(port);
	std::cout << str << std::endl;
}

void rtype::TCPClient::receive()
{
	asio::async_read(*_socket, asio::buffer(_reply, 8192), std::bind(&rtype::TCPClient::doRead, this, std::placeholders::_1, std::placeholders::_2));
	std::this_thread::sleep_for(std::chrono::nanoseconds(10000));
	auto i = 0;
	std::chrono::steady_clock::time_point lastTick = std::chrono::steady_clock::now();
	std::chrono::nanoseconds dtime;
	while (dtime.count() < 10000) {
		std::chrono::steady_clock::time_point currentTick = std::chrono::steady_clock::now();
		if (_reply[0] != 42)
			break;
		dtime = currentTick - lastTick;
		lastTick = currentTick;
	}
	if (_reply[0] != 42)
		std::cout << "received \"";
	for (; _reply[i] != 42; i++) { std::cout << (int)_reply[i]; std::cout << "."; }
	if (i)
		std::cout << "\"" << std::endl;
	_buffer->putInBuffer(i, _reply);
	std::memset(_reply, 42, 8192);
}

void rtype::TCPClient::doRead(const std::error_code& ec, size_t bytes)
{
	(void)bytes;
	(void)ec;
}

void rtype::TCPClient::send(IPacket& packet)
{
	asio::async_write(*_socket, asio::buffer(packet.unpack()), std::bind(&rtype::TCPClient::doWrite, this, std::placeholders::_1, std::placeholders::_2));
}

void rtype::TCPClient::doWrite(const std::error_code& ec, size_t bytes)
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
	_logger.logln(std::string{ "Client disconnect" });
}


bool rtype::TCPClient::isConnected()
{
	return (_isConnected);
}
