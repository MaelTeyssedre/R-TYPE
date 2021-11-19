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

void BasicMonster::init(Registry &registry)
{
	std::cout << "isEntering" << std::endl;
	AMonster::setVelocity(std::pair(10, 0));
	AMonster::setFireFrequence(3);
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