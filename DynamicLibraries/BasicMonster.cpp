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

void BasicMonster::init(Registry &)
{
    std::cout << "Init Basic monster" << std::endl;
}

void BasicMonster::update()
{
    std::cout << "Update Basic monster" << std::endl;
}