#include "Room.hpp"
#include "Game.hpp"

rtype::Room::Room(std::vector<PlayerData>* players)
	: _threadPtr(new std::thread(_runThread, players)) {
	std::cout << "in room" << std::endl;
}

auto rtype::Room::_runThread(std::vector<PlayerData>* players) -> void
{
	std::cout << "in room" << std::endl;
	Game game{players};
	for (;;) {
		game.runGame();
		std::this_thread::sleep_for(std::chrono::nanoseconds(10000));	
		std::cout << "size inside of the room : " << players->size() << std::endl;
	}
}