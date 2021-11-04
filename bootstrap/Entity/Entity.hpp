/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "Registry.hpp"

class Entity {
    public:
        operator size_t() const;
    protected:
        friend class Registry;
        explicit Entity(size_t id);
        ~Entity() = default;
    private:
        size_t _id;

};

#endif /* !ENTITY_HPP_ */
