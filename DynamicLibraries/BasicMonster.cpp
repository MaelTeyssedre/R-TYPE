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
        std::cout << "I would kill someone to see you!!" << std::endl;
		return new BasicMonster();
	}

	__declspec (dllexport) void deleter(IElement *ptr)
	{
		delete ptr;
	}
}
#endif

void BasicMonster::init(std::shared_ptr<int>)
{
    std::cout << "Init Basic monster" << std::endl;
}

void BasicMonster::update()
{
}