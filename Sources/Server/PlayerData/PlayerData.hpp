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
            explicit PlayerData() = default;
            explicit PlayerData(size_t, std::shared_ptr<Buffer>, std::shared_ptr<Buffer>, std::shared_ptr<std::mutex>, std::shared_ptr<std::mutex>);
            // ! issue julian
            //PlayerData(PlayerData &) = delete;
            virtual ~PlayerData() = default;
            size_t getId(void) const;
            // ! issue julian
            //PlayerData& operator=(PlayerData &PlayerData) = delete;
            std::shared_ptr<std::mutex> _mutexIn;
            std::shared_ptr<std::mutex> _mutexOut;
            std::shared_ptr<Buffer> _bufferIn;
            std::shared_ptr<Buffer> _bufferOut;
        private:
            size_t _id;
    };

#endif /* !PLAYERDATA_HPP_ */
