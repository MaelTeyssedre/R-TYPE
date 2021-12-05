#include "Components.hpp"
#include "Wall.hpp"

void rtype::Wall::init(Registry &registry)
{
    Entity _idx = registry.spawnEntity();

    struct components::position_s pos {100, 100};
    struct components::size_s size {100, 100};
    struct components::types_s type {constants::WALL};
    struct components::index_s index {(size_t)_idx};

    registry.addComponent<components::position_s>(registry.entityFromIndex(_idx), std::move(pos));
    registry.addComponent<components::size_s>(registry.entityFromIndex(_idx), std::move(size));
    registry.addComponent<components::types_s>(registry.entityFromIndex(_idx), std::move(type));
    registry.addComponent<components::index_s>(registry.entityFromIndex(_idx), std::move(index));
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
