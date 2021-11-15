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
	_id = _registry.spawnEntity();

	registry.registerComponent<position_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
}

void BalkanyMonster::update()
{
}