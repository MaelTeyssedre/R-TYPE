#include "BasicMonster.hpp"

#ifdef __linux__
	extern "C"
	{
		rtype::BasicMonster *allocator()
		{
			return new rtype::BasicMonster();
		}

		void deleter(rtype::BasicMonster *ptr)
		{
			delete ptr;
		}
	}
#endif

#ifdef _WIN32
	extern "C"
	{
		__declspec(dllexport) rtype::BasicMonster *allocator()
		{
			return new rtype::BasicMonster();
		}

		__declspec(dllexport) void deleter(rtype::BasicMonster *ptr)
		{
			delete ptr;
		}
	}
#endif

rtype::BasicMonster::BasicMonster()
	: AMonster("testName", "randomPath")
{
}

void rtype::BasicMonster::init(Registry &registry)
{
	setVelocity(std::pair(10, 0));
	setFireFrequence(3);
	_registry = registry;
	_idx = _registry.spawnEntity();
	registry.registerComponent<components::position_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<components::velocity_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<components::weapon_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<components::healPoint_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<components::fireFrequence_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.registerComponent<components::loot_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
	registry.addComponent<components::position_s>(registry.entityFromIndex(_idx), std::move(_position));
	registry.addComponent<components::velocity_s>(registry.entityFromIndex(_idx), std::move(_velocity));
	registry.addComponent<components::weapon_s>(registry.entityFromIndex(_idx), std::move(_weapon));
	registry.addComponent<components::healPoint_s>(registry.entityFromIndex(_idx), std::move(_healPoint));
	registry.addComponent<components::fireFrequence_s>(registry.entityFromIndex(_idx), std::move(_fireFrequence));
	registry.addComponent<components::loot_s>(registry.entityFromIndex(_idx), std::move(_loot));
}

void rtype::BasicMonster::update()
{
	_registry.addSystem([](Registry &r, SparseArray<components::position_s> &position, SparseArray<components::velocity_s> &velocity) -> void
						{
							(void)r;
							for (size_t i = 0; i < position.size() && i < velocity.size(); i++)
							{
								std::optional<components::position_s> &pos = position[i];
								const std::optional<components::velocity_s> &vel = velocity[i];
								if (pos && vel)
								{
									pos.value().x += vel.value().vx;
									pos.value().y += vel.value().vy;
								}
							}
						},
						_registry.getComponents<components::position_s>(), _registry.getComponents<components::velocity_s>());
}
