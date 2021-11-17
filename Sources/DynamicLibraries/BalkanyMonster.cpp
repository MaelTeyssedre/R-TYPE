/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** BalkanyMonster
*/

#include "BalkanyMonster.hpp"

#ifdef __linux__
	extern "C"
	{
		IElement *allocator()
		{
			return new BalkanyMonster();
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
			return new BalkanyMonster();
		}

		__declspec (dllexport) void deleter(IElement *ptr)
		{
			delete ptr;
		}
	}
#endif

void BalkanyMonster::init(Registry &registry)
{
	_registry = registry;
	// _idx = _registry.spawnEntity();

	// registry.registerComponent<component::position_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	// registry.registerComponent<component::velocity_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	// registry.registerComponent<component::weapon_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	// registry.registerComponent<component::healPoint_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	// registry.registerComponent<component::fireFrequence_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	// registry.registerComponent<component::loot_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	// registry.addComponent<component::position_s>(registry.entityFromIndex(_idx), std::move(_pos));
	// registry.addComponent<component::velocity_s>(registry.entityFromIndex(_idx), std::move(_vel));
	// registry.addComponent<component::weapon_s>(registry.entityFromIndex(_idx), std::move(_weapon));
	// registry.addComponent<component::healPoint_s>(registry.entityFromIndex(_idx), std::move(_healPoint));
	// registry.addComponent<component::fireFrequence_s>(registry.entityFromIndex(_idx), std::move(_fireFrequence));
	// registry.addComponent<component::loot_s>(registry.entityFromIndex(_idx), std::move(_loot));
	// registry.addSystem(moveMonsterSystem, registry.getComponents<component::position_s>(), registry.getComponents<component::velocity_s>());
	// registry.addSystem(monsterLoseHealthSystem, registry.getComponents<component::healPoint_s>(), registry.getComponents<component::weapon_s>());
}

void BalkanyMonster::update()
{
}


// void BalkanyMonster::setName(std::string &name)
// {
//     _name = name;
// }
                
// std::string BalkanyMonster::getName() const
// {
//     return(_name);
// }

// void BalkanyMonster::setPosition(component::position_s &position)
// {
//     _position.x = position.x;
//     _position.y = position.y;
// }

// component::position_s BalkanyMonster::getPosition() const
// {
//     return (_position);
// }
