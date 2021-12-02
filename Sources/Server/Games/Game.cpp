#include "Game.hpp"
#include "UpdateTime.hpp"
#include <thread>
#include <memory>
#include <chrono>

rtype::Game::Game(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer)
    : _r(Registry(2)), _roomBuffer(roomBuffer)
{
}

void rtype::Game::run()
{
    waitForStartingGame();
}

void rtype::Game::waitForStartingGame()
{
    std::cout << "IN GAME" << std::endl;
}