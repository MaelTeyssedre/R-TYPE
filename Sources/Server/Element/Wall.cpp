/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Wall
*/

#include "Wall.hpp"

void Wall::init(Registry &registry) 
{
    _registry = registry;
	_idx = _registry.spawnEntity();
}

// void Wall::setPosition(component::position_s &position)
// {
//     _position.x = position.x;
//     _position.y = position.y;
// }

// component::position_s Wall::getPosition() const
// {
//     return (_position);
// }

void Wall::update()
{
}

void Wall::setName(std::string &name)
{
    _name = name;
}
                
std::string &Wall::getName() const
{
    return(_name);
}
