#include "Player.hpp"
#include "Position.hpp"
#include "HealPoint.hpp"
#include "Weapon.hpp"
#include "Velocity.hpp"
#include "FireFrequence.hpp"
#include "Constants.hpp" 
#include "Components.hpp" 

void rtype::Player::init(Registry &registry)
{
    Entity _idx = registry.spawnEntity();

    struct rtype::components::position_s pos {100, 100};
    struct rtype::components::velocity_s vel {10, 10};
    struct rtype::components::healPoint_s healPoint {100};
    struct rtype::components::weapon_s weapon {10};
    struct rtype::components::fireFrequence_s fireFrequence {2};
    struct rtype::components::types_s type {rtype::constants::WALL};
    struct rtype::components::index_s index {_idx};
    
    registry.addComponent<rtype::components::position_s>(registry.entityFromIndex(_idx), std::move(pos));
	registry.addComponent<rtype::components::velocity_s>(registry.entityFromIndex(_idx), std::move(vel));
	registry.addComponent<rtype::components::weapon_s>(registry.entityFromIndex(_idx), std::move(weapon));
	registry.addComponent<rtype::components::healPoint_s>(registry.entityFromIndex(_idx), std::move(healPoint));
	registry.addComponent<rtype::components::fireFrequence_s>(registry.entityFromIndex(_idx), std::move(fireFrequence));
    registry.addComponent<rtype::components::types_s>(registry.entityFromIndex(_idx), std::move(type));
    registry.addComponent<rtype::components::index_s>(registry.entityFromIndex(_idx), std::move(index));
}

void rtype::Player::update()
{
}

void rtype::Player::setName(std::string &name)
{
    _name = name;
}

std::string &rtype::Player::getName()
{
    return _name;
}
