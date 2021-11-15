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

void BalkanyMonster::moveMonsterSystem(Registry &r, SparseArray<position_s> &positions, SparseArray<velocity_s> &velocity) {
    for (size_t i = 0; i < positions.size(); i++) {
        std::optional<velocity_s> &vel = velocity[i];
        std::optional<position_s> &pos = positions[i];
		if (vel && pos) {
        	pos.value().x -= vel.value().vx;
			pos.value().y -= vel.value().vy;
		}
    }
}

void BalkanyMonster::init(Registry &registry)
{
	_registry = registry;
	_idx = _registry.spawnEntity();

	registry.registerComponent<position_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<velocity_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<weapon_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<healPoint_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<fireFrequence_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.addComponent<position_s>(registry.entityFromIndex(_idx), std::move(_pos));
	registry.addComponent<velocity_s>(registry.entityFromIndex(_idx), std::move(_vel));
	registry.addComponent<weapon_s>(registry.entityFromIndex(_idx), std::move(_weapon));
	registry.addComponent<healPoint_s>(registry.entityFromIndex(_idx), std::move(_healPoint));
	registry.addComponent<fireFrequence_s>(registry.entityFromIndex(_idx), std::move(_fireFrequence));
	registry.addSystem(moveMonsterSystem, registry.getComponents<position_s>(), registry.getComponents<velocity_s>());
}

void BalkanyMonster::update()
{
}