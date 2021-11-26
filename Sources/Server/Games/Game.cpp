#include "Game.hpp"

Game::Game(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer)
    : _r(Registry(2)), _roomBuffer(roomBuffer)
{
}

void Game::run() {
    waitPlayer();
    startGame();
}

void Game::waitPlayer()
{
    while (_roomBuffer->size() != 4) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Game::startGame()
{}

