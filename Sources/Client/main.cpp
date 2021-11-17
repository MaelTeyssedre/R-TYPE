/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** main
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "asio.hpp"
#include "Packet.hpp"
#include "TCPClient.hpp"
#include "NetworkManager.hpp"

using asio::ip::tcp;

enum { max_length = 1024 };

int main(int argc, char* argv[])
{
  NetworkManager net;

  std::cout << "before create tcp client" << std::endl;

  ITCPClient *client =  net.createTCPClient(1332);
  std::cout << "after create tcp client" << std::endl;


  std::string str = "hello from server";
  std::vector<uint8_t> vec;

  Packet packet;

  vec.assign(str.begin(), str.end());
  packet.pack(vec);
  std::cout << "before loop" << std::endl;
  while (1) {
    client->receive();
    client->send(packet);
  }
 /* asio::io_context context;
  auto sock = std::make_shared<asio::ip::tcp::socket>(context);

  TCPClient client(context, sock, "127.0.0.1", "1342");
  context.run();
  Packet packet;

  std::string str = "hello from server";
  std::vector<uint8_t> vec;

  vec.assign(str.begin(), str.end());
  packet.pack(vec);
  while (1) {
    client.receive();
    client.send(packet);
  }*/
  return 0;
}