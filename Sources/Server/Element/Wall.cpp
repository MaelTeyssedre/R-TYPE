#include "Wall.hpp"
#include "Position.hpp"

void rtype::Wall::init(Registry &registry)
{
    struct components::position_s pos {100, 100};
    //struct components::size_s size {100, 100};
    Entity _idx = registry.spawnEntity();
    registry.addComponent<components::position_s>(registry.entityFromIndex(_idx), std::move(pos));
    //registry.addComponent<components::size_s>(registry.entityFromIndex(_idx), std::move(size));
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
