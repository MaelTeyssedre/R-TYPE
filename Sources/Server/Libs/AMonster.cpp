#include "AMonster.hpp"

void rtype::AMonster::setHealPoint(size_t healPoint)
{
    _healPoint.healPoint = healPoint;
}

rtype::components::healPoint_s rtype::AMonster::getHealPoint() const
{
    return (_healPoint);
}

void rtype::AMonster::setFireFrequence(size_t fireFrequence)
{
    _fireFrequence.fireFrequence = fireFrequence;
}

rtype::components::fireFrequence_s rtype::AMonster::getFireFrequence() const
{
    return (_fireFrequence);
}

void rtype::AMonster::setWeapon(size_t weapon)
{
    _weapon.weapon = weapon;
}

rtype::components::weapon_s rtype::AMonster::getWeapon() const
{
    return (_weapon);
}

void rtype::AMonster::setPosition(std::pair<int, int> pos)
{
    _position.x = pos.first;
    _position.y = pos.second;
}

rtype::components::position_s rtype::AMonster::getPosition() const
{
    return (_position);
}

void rtype::AMonster::setVelocity(std::pair<int, int> vel)
{
    _velocity.vx = vel.first;
    _velocity.vy = vel.second;
}

rtype::components::velocity_s rtype::AMonster::getVelocity() const
{
    return (_velocity);
}

void rtype::AMonster::setName(std::string &name)
{
    _name = name;
}

std::string rtype::AMonster::getName()
{
    return (_name);
}
