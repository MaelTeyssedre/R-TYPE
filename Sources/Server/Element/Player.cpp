/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Player
*/

#include "Player.hpp"

void Player::init(Registry &registry) 
{
    _registry = registry;
	_idx = _registry.spawnEntity();
}

void Player::update()
{
}

// void Player::setHealPoint(component::healPoint_s &healPoint)
// {
//     _healPoint.healPoint = healPoint.healPoint;
// }

// component::healPoint_s Player::getHealPoint() const
// {
//     return (_healPoint);
// }

// void Player::setFireFrequence(component::fireFrequence_s &fireFrequence)
// {
//     _fireFrequence.fireFrequence = fireFrequence.fireFrequence;
// }
            
// component::fireFrequence_s Player::getFireFrequence() const
// {
//     return (_fireFrequence);
// }

// void Player::setWeapon(component::weapon_s &weapon)
// {
//     _weapon.weaponType = weapon.weaponType;
// }

// component::weapon_s Player::getWeapon() const
// {
//     return (_weapon);
// }

// void Player::setPosition(component::position_s &position)
// {
//     _position.x = position.x;
//     _position.y = position.y;
// }

// component::position_s Player::getPosition() const
// {
//     return (_position);
// }

void Player::setName(std::string &name)
{
    _name = name;
}
                
std::string &Player::getName()
{
    return(_name);
}
