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
        //PlayerData();
        PlayerData(size_t, std::shared_ptr<Buffer>, std::shared_ptr<Buffer>);
        ~PlayerData() = default;
        size_t getId(void) const;
        //mutable std::mutex _mutexIn;
        //mutable std::mutex _mutexOut;
        std::shared_ptr<Buffer> _bufferIn;
        std::shared_ptr<Buffer> _bufferOut;
    protected:
    private:
        size_t _id;
};

#endif /* !PLAYERDATA_HPP_ */
