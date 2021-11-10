/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** TCPServer
*/

#ifndef TCPSERVER_HPP_
#define TCPSERVER_HPP_

#include "Packet.hpp"
#include "tcpUser.hpp"
#include "ITCPServer.hpp"
#include <map>


class TCPServer { // : public ITCPServer {
    public:
        TCPServer() = default;
        TCPServer(asio::io_context &context, std::uint16_t port);
        ~TCPServer() = default;
     //   void send(IPacket &data) override;
      //  void send(tcpUser &user, IPacket &data);
     //   void send(std::vector<size_t> targets, IPacket &data) override;
     //   void sendToAll(IPacket &data) override;
     //   std::shared_ptr<IPacket> receive() override;
     //   void start() override;
      //  void stop() override;
      //  void eject(size_t client) override;
       // asio::ip::tcp::socket getUserSocket(int id);
        void accept();

    protected:
    private:
     /*   void doAccept();
        void doRead();
        void doWrite(const std::error_code &ec, size_t bytes);*/
     //   std::map<size_t, tcpUser> _users;
        asio::io_context &_context;
        asio::ip::tcp::acceptor _acceptor;
      //  asio::ip::tcp::socket &_socket;
};

#endif /* !TCPSERVER_HPP_ */

