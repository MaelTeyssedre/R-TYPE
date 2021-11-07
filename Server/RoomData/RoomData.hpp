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
        ~RoomData();

        std::vector<std::pair<size_t, PlayerData>> &getRoomData();
        void setRoomData(std::vector<std::pair<size_t, PlayerData>>);
    protected:
    private:
        std::vector<std::pair<size_t, PlayerData>> _roomData;
};

#endif /* !ROOMDATA_HPP_ */
