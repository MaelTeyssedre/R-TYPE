#include "Room.hpp"

rtype::Room::Room(std::vector<PlayerData>* players)
	: _threadPtr(new std::thread(_runThread, players)) {}

auto rtype::Room::_runThread(std::vector<PlayerData>* players) -> void
{
	for (;;);
		// std::cout << "size insode of the room : " << players->size() << std::endl;
}