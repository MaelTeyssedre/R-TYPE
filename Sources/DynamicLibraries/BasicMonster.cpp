/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** BasicMonster
*/

#include "BasicMonster.hpp"

#ifdef __linux__
	extern "C"
	{
		IElement *allocator()
		{
			return new BasicMonster();
		}

		void deleter(IElement *ptr)
		{
			delete ptr;
		}
	}
#endif

#ifdef _WIN32
	extern "C"
	{
		__declspec (dllexport) IElement *allocator()
		{
			return new BasicMonster();
		}

		__declspec (dllexport) void deleter(IElement *ptr)
		{
			delete ptr;
		}
	}
#endif

BasicMonster::BasicMonster()
{
    _name = "testName";
    _healPoint.healPoint = 50;
    _fireFrequence.fireFrequence = 30;
    _weapon.weapon = 0;
    _position.x = 0;
    _position.y = 0;
    _velocity.vx = 0;
    _velocity.vy = 0;
}

void BasicMonster::init(Registry &registry)
{
	std::cout << "isEntering" << std::endl;
	setVelocity(std::pair(10, 0));
	setFireFrequence(3);
	_registry = registry;
	_idx = _registry.spawnEntity();
	registry.registerComponent<rtype::position_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<rtype::velocity_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<rtype::weapon_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<rtype::healPoint_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<rtype::fireFrequence_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<rtype::loot_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.addComponent<rtype::position_s>(registry.entityFromIndex(_idx), std::move(_position));
	registry.addComponent<rtype::velocity_s>(registry.entityFromIndex(_idx), std::move(_velocity));
	registry.addComponent<rtype::weapon_s>(registry.entityFromIndex(_idx), std::move(_weapon));
	registry.addComponent<rtype::healPoint_s>(registry.entityFromIndex(_idx), std::move(_healPoint));
	registry.addComponent<rtype::fireFrequence_s>(registry.entityFromIndex(_idx), std::move(_fireFrequence));
	registry.addComponent<rtype::loot_s>(registry.entityFromIndex(_idx), std::move(_loot));
	std::cout << "isWorking" << std::endl;
}

void BasicMonster::update()
{
	_registry.addSystem([](Registry &r, SparseArray<rtype::position_s> &position, SparseArray<rtype::velocity_s> &velocity) -> void {
		for (size_t i = 0; i < position.size() && i < velocity.size(); i++) {
			std::optional<rtype::position_s> &pos = position[i];
			const std::optional<rtype::velocity_s> &vel = velocity[i];
			if (pos && vel)
				pos.value().x += vel.value().vx;
				pos.value().y += vel.value().vy;
		}
	}, _registry.getComponents<rtype::position_s>(), _registry.getComponents<rtype::velocity_s>());
}

void BasicMonster::setHealPoint(size_t healPoint)
{
    _healPoint.healPoint = healPoint;
}

rtype::healPoint_s BasicMonster::getHealPoint() const
{
    return (_healPoint);
}

void BasicMonster::setFireFrequence(size_t fireFrequence)
{
    _fireFrequence.fireFrequence = fireFrequence;
}
            
rtype::fireFrequence_s BasicMonster::getFireFrequence() const
{
    return (_fireFrequence);
}

void BasicMonster::setWeapon(size_t weapon)
{
    _weapon.weapon = weapon;
}

rtype::weapon_s BasicMonster::getWeapon() const
{
    return (_weapon);
}

void BasicMonster::setPosition(std::pair<int, int> pos)
{
    _position.x = pos.first;
    _position.y = pos.second;
}

rtype::position_s BasicMonster::getPosition() const
{
    return (_position);
}

void BasicMonster::setVelocity(std::pair<int, int> vel)
{
    _velocity.vx = vel.first;
    _velocity.vy = vel.second;
}

rtype::velocity_s BasicMonster::getVelocity() const
{
    return (_velocity);
}

void BasicMonster::setName(std::string &name)
{
    std::cout << "inside the setName function : _name" << std::endl;
    _name = name;
    std::cout << "Set your f*cking name" << std::endl;
}

std::string BasicMonster::getName()
{
    std::cout << "inside the getName function : "  << _name << std::endl;
    return(_name);
}
