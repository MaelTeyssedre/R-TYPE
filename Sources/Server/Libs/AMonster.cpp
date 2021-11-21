#include "AMonster.hpp"

void AMonster::setHealPoint(size_t healPoint)
{
    _healPoint.healPoint = healPoint;
}

rtype::healPoint_s AMonster::getHealPoint() const
{
    return (_healPoint);
}

void AMonster::setFireFrequence(size_t fireFrequence)
{
    _fireFrequence.fireFrequence = fireFrequence;
}

rtype::fireFrequence_s AMonster::getFireFrequence() const
{
    return (_fireFrequence);
}

void AMonster::setWeapon(size_t weapon)
{
    _weapon.weapon = weapon;
}

rtype::weapon_s AMonster::getWeapon() const
{
    return (_weapon);
}

void AMonster::setPosition(std::pair<int, int> pos)
{
    _position.x = pos.first;
    _position.y = pos.second;
}

rtype::position_s AMonster::getPosition() const
{
    return (_position);
}

void AMonster::setVelocity(std::pair<int, int> vel)
{
    _velocity.vx = vel.first;
    _velocity.vy = vel.second;
}

rtype::velocity_s AMonster::getVelocity() const
{
    return (_velocity);
}

void AMonster::setName(std::string &name)
{
    _name = name;
}

std::string AMonster::getName()
{
    return (_name);
}
