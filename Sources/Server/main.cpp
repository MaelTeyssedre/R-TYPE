#include <iostream>
#include "NetworkManager.hpp"
#include "RoomManager.hpp"
#include "PacketManager.hpp"
#include "Constants.hpp"
#include <csignal>

static bool status = true;

void signalHandler(int signum)
{
    (void)signum;
    std::cout << "Goodbye" << std::endl;
    status = false;
}

int main(int ac, char **av)
{
    (void)ac;
    std::shared_ptr<std::vector<std::vector<rtype::PlayerData>>> roomList;
    std::shared_ptr<Buffer> bufferIn{new Buffer(BUF_SIZE)};
    std::shared_ptr<Buffer> bufferOut{new Buffer(BUF_SIZE)};
    INetworkManager *netManager = new rtype::NetworkManager();
    rtype::RoomManager roomManager(roomList, bufferIn, bufferOut);
    rtype::PacketManager packetManager(bufferOut, bufferIn);
    ITCPServer *server = netManager->createTCPServer(std::stoi(av[1]));
    netManager->start();
    signal(SIGINT, signalHandler);
    while (status == true)
    {
        server->receive();
        for (auto i : packetManager.getRequests())
            packetManager.managePacket(i);
        roomManager.manageRoom();
        std::this_thread::sleep_for(std::chrono::nanoseconds(1000000));
    }
}

/*
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

using asio::ip::tcp;

class session
  : public std::enable_shared_from_this<session>
{
public:
  session(tcp::socket socket)
    : socket_(std::move(socket))
  {
  }

  void start()
  {
    do_read();
  }

private:
  void do_read()
  {
    auto self(shared_from_this());
    socket_.async_read_some(asio::buffer(data_, max_length),
        [this, self](std::error_code ec, std::size_t length)
        {
          if (!ec)
          {
            if (length != 0) {
              std::cout << (uint8_t)data_[0] << std::endl;
              std::cout << (uint8_t)data_[1] << std::endl;
              std::cout << (uint8_t)data_[2] << std::endl;
              std::cout << (uint8_t)data_[3] << std::endl;
              std::cout << (uint8_t)data_[4] << std::endl;
              std::cout << (uint8_t)data_[5] << std::endl;
              std::cout << (uint8_t)data_[6] << std::endl;
              std::cout << (uint8_t)data_[7] << std::endl;
              std::cout << (uint8_t)data_[8] << std::endl;
              std::cout << (uint8_t)data_[9] << std::endl;
            }
            do_write(length);
          }
        });
  }

  void do_write(std::size_t length)
  {
    auto self(shared_from_this());
    asio::async_write(socket_, asio::buffer(data_, length),
        [this, self](std::error_code ec, std::size_t)
        {
          if (!ec)
          {
            do_read();
          }
        });
  }

  tcp::socket socket_;
  enum { max_length = 1024 };
  char data_[max_length];
};

class server
{
public:
  server(asio::io_context& io_context, short port)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)),
      socket_(io_context)
  {
    do_accept();
  }

private:
  void do_accept()
  {
    acceptor_.async_accept(socket_,
        [this](std::error_code ec)
        {
          if (!ec)
          {
            std::make_shared<session>(std::move(socket_))->start();
          }

          do_accept();
        });
  }

  tcp::acceptor acceptor_;
  tcp::socket socket_;
};

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: async_tcp_echo_server <port>\n";
      return 1;
    }

    asio::io_context io_context;

    server s(io_context, std::atoi(argv[1]));

    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}*/