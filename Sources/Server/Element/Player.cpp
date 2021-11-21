#include "Player.hpp"

void Player::init(Registry &registry)
{
    _registry = registry;
    _idx = _registry.spawnEntity();
}

void Player::update()
{
}

void Player::setName(std::string &name)
{
    _name = name;
}

std::string &Player::getName()
{
    return _name;
}
