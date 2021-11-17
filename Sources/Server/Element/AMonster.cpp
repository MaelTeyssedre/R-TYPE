/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** AMonster
*/

#include "AMonster.hpp"

// void AMonster::setHealPoint(component::healPoint_s &healPoint)
// {
//     _healPoint.healPoint = healPoint.healPoint;
// }

// component::healPoint_s AMonster::getHealPoint() const
// {
//     return (_healPoint);
// }

// void AMonster::setFireFrequence(component::fireFrequence_s &fireFrequence)
// {
//     _fireFrequence.fireFrequence = fireFrequence.fireFrequence;
// }
            
// component::fireFrequence_s AMonster::getFireFrequence() const
// {
//     return (_fireFrequence);
// }

// void AMonster::setWeapon(component::weapon_s &weapon)
// {
//     _weapon.weaponType = weapon.weaponType;
// }

// component::weapon_s AMonster::getWeapon() const
// {
//     return (_weapon);
// }

// void AMonster::setPosition(component::position_s &position)
// {
//     _position.x = position.x;
//     _position.y = position.y;
// }

// component::position_s AMonster::getPosition() const
// {
//     return (_position);
// }

// void AMonster::setVelocity(component::velocity_s &velocity)
// {
//     _velocity.vx = velocity.vx;
//     _velocity.vy = velocity.vy;
// }

// component::velocity_s AMonster::getVelocity() const
// {
//     return (_velocity);
// }

void AMonster::setName(std::string &name)
{
    _name = name;
}
                
std::string &AMonster::getName() const
{
    return(_name);
}
