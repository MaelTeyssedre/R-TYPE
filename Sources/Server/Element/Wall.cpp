#include "Wall.hpp"
#include "Position.hpp"

void rtype::Wall::init(Registry &registry)
{
    struct components::position_s pos {100, 100};
 //BUG ICI !!!!!   
    _registry = registry;
    _idx = _registry.spawnEntity();
    registry.addComponent<components::position_s>(registry.entityFromIndex(_idx), std::move(pos));
}

void rtype::Wall::update()
{
}

void rtype::Wall::setName(std::string &name)
{
    _name = name;
}

std::string &rtype::Wall::getName()
{
    return (_name);
}
