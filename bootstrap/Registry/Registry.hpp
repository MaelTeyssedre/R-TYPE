/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Registry
*/

#ifndef REGISTRY_HPP_
#define REGISTRY_HPP_

#include "../SparseArray/SparseArray.hpp"
#include <map>
#include <typeindex>
#include <any>

class Registry {
    public:
        template <class Component>
        SparseArray<Component> &registerComponent();

        template <class Component>
        SparseArray<Component> &getComponents();

        template <class Component>
        SparseArray<Component> const &getComponents() const;
    
    private:
        std::map<std::type_index, std::any> _components_arrays;
};

#endif /* !REGISTRY_HPP_ */
