#include "Room.hpp"
#include "Game.hpp"

rtype::Room::Room(std::vector<PlayerData>* players)
	: _threadPtr(new std::thread(_runThread, players)) {
}

auto rtype::Room::_runThread(std::vector<PlayerData>* players) -> void
{
	Game game {players};
	game.runGame();
	std::cout << "end of game" << std::endl;;
}