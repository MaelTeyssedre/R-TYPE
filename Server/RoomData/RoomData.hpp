/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** RoomData
*/

#ifndef ROOMDATA_HPP_
#define ROOMDATA_HPP_

#include "PlayerData.hpp"

class RoomData {
    public:
        RoomData();
        RoomData(RoomData&);
        RoomData& operator=(RoomData &);
        ~RoomData() = default;

        std::pair<size_t, std::vector<PlayerData>> &getRoomData();
        void setRoomData(std::pair<size_t, std::vector<PlayerData>>);
    protected:
    private:
        std::pair<size_t, std::vector<PlayerData>> _roomData;
};

#endif /* !ROOMDATA_HPP_ */
