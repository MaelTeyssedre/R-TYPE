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
#include "../Entity/Entity.hpp"
#include <any>
#include <functional>

class Registry {
    public:
        template <class Component>
        explicit Registry() {};

        virtual ~Registry() = default;

        template <class Component>
        SparseArray<Component> &registerComponent(std::function<void(Registry &, Entity const &)>constructor, std::function<void(Registry &, Entity const &)>destructor) {
            _componentsArrays.insert(std::make_pair(std::type_index(Component), SparseArray<Component>()));
            _constructorArray.insert(std::make_pair(std::type_index(Component), constructor));
            _destructorArray.insert(std::make_pair(std::type_index(Component), destructor));
            return std::any_cast(_componentsArrays[std::type_index(Component)]);
        }

        template <class Component>
        SparseArray<Component> &getComponents() {
            return std::any_cast(_componentsArrays[std::type_index(Component)]);
        }

        template <class Component>
        SparseArray<Component> const &getComponents() const {
            return std::any_cast(_componentsArrays[std::type_index(Component)]);
        }

        Entity spawnEntity() {
            if (_killedEntities.empty()) {
                _entities++;
                return Entity(_entities);
            }
            _killedEntities.pop_back();
            return Entity(_killedEntities.size() + 1); 
        }

        Entity entityFromIndex(size_t idx) {
            return Entity(idx);
        }

        void killEntity(Entity const &e) {
            for (auto i : _componentsArrays) {
                
            }
        }

        template <typename Component>
        typename SparseArray<Component>::reference_type addComponent(Entity const &to, Component &&c) {
            SparseArray<Component> *sparseArray = std::any_cast<SparseArray<Component>>(_componentsArrays[to]);
            return sparseArray->insertAt(to, c);
        }

        template <typename Component, typename ...Params>
        typename SparseArray<Component>::reference_type emplaceComponent(Entity const &to, Params &&...p) {
            SparseArray<Component> *sparseArray = std::any_cast<SparseArray<Component>>(_componentsArrays[to]);

        }

        template <typename Component>
        void removeComponent(Entity const &from) {

        }

    private:
        std::map<std::type_index, std::function<void(Registry &, Entity const &)>> _constructorArray;
        std::map<std::type_index, std::function<void(Registry &, Entity const &)>> _destructorArray;
        std::map<std::type_index, std::any> _componentsArrays;
        size_t _entities;
        std::vector<Entity> _killedEntities;
};

#endif /* !REGISTRY_HPP_ */
