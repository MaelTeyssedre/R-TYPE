#include "Room.hpp"
#include "Game.hpp"

rtype::Room::Room(std::vector<PlayerData>* players)
	: _threadPtr(new std::thread(_runThread, players)) {
}

auto rtype::Room::_runThread(std::vector<PlayerData>* players) -> void
{
	Game game {players};
	for (;;) {
		game.runGame();
		std::this_thread::sleep_for(std::chrono::nanoseconds(10000));	
	}
}