/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

class Entity {
    public:
        explicit Entity(size_t id);
        ~Entity() = default;
        operator size_t() const;
    private:
        size_t _id;

};

#endif /* !ENTITY_HPP_ */
