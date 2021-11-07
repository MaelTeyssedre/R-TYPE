/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** PlayerData
*/

#ifndef PLAYERDATA_HPP_
#define PLAYERDATA_HPP_

#include <mutex>
#include <vector>
#include "Buffer.hpp"

class PlayerData {
    public:
        PlayerData() = default;
        PlayerData(size_t);
        ~PlayerData() = default;
        size_t getId(void) const;
        //mutable std::mutex _mutexIn;
        //mutable std::mutex _mutexOut;
        Buffer _bufferIn;
        Buffer _bufferOut;
    protected:
    private:
        size_t _id;
};

#endif /* !PLAYERDATA_HPP_ */
