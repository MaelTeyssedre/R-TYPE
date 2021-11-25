/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** RtypeServer
*/

#ifndef RTYPESERVER_HPP_
#define RTYPESERVER_HPP_



class RtypeServer {
    public:
        explicit RtypeServer() = default;
        explicit RtypeServer(int port);
        virtual ~RtypeServer() = default;
    
    private:
        int _port;
};

#endif /* !RTYPESERVER_HPP_ */
