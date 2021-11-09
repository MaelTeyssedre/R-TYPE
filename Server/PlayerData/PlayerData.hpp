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
#include <memory>
#include "Buffer.hpp"

class PlayerData {
    public:
        PlayerData() = default;
        PlayerData(size_t, std::shared_ptr<Buffer>, std::shared_ptr<Buffer>, std::shared_ptr<std::mutex>, std::shared_ptr<std::mutex>);
        //PlayerData(PlayerData &) = delete;
        ~PlayerData() = default;
        size_t getId(void) const;
        //PlayerData& operator=(PlayerData &PlayerData) = delete;
        std::shared_ptr<std::mutex> mutexIn;
        std::shared_ptr<std::mutex> mutexOut;
        std::shared_ptr<Buffer> bufferIn;
        std::shared_ptr<Buffer> bufferOut;
    protected:
    private:
        size_t _id;
};

#endif /* !PLAYERDATA_HPP_ */
