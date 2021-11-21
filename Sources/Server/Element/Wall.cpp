#include "Wall.hpp"

void Wall::init(Registry &registry)
{
    _registry = registry;
    _idx = _registry.spawnEntity();
}

void Wall::update()
{
}

void Wall::setName(std::string &name)
{
    _name = name;
}

std::string &Wall::getName()
{
    return (_name);
}
