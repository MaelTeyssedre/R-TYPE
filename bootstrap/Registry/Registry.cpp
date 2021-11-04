/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Registry
*/

#include "Registry.hpp"

Registry::Registry(size_t nbEntity)
    : _entities(nbEntity) {}

template <class Component>
SparseArray<Component> &Registry::registerComponent(std::function<void(Registry &, Entity const &)> constructor, std::function<void(Registry &, Entity const &)> destructor) {
    _componentsArrays.insert(std::make_pair(std::type_index(Component), SparseArray<Component>(_entities)));
    _constructorArray.insert(std::make_pair(std::type_index(Component), constructor));
    _destructorArray.insert(std::make_pair(std::type_index(Component), destructor));
    return std::any_cast(_componentsArrays[std::type_index(Component)]);
}

template <class Component>
SparseArray<Component> &Registry::getComponents() {
    return std::any_cast(_componentsArrays[std::type_index(Component)]);
}

template <class Component>
SparseArray<Component> const &Registry::getComponents() const {
    return std::any_cast(_componentsArrays[std::type_index(Component)]);
}

Entity Registry::spawnEntity() {
    if (_killedEntities.empty()) {
        _entities++;
        for (auto i : _componentsArrays)
            _constructorArray[i.first](*this, Entity(_entities));
        return Entity(_entities);
    }
    Entity respawnedEntity = _killedEntities.back();
    _killedEntities.pop_back();
    for (auto i : _componentsArrays)
            _constructorArray[i.first](*this, Entity(respawnedEntity));
    return respawnedEntity;
}

Entity Registry::entityFromIndex(size_t idx) {
    if (idx >= _entities)
        throw std::invalid_argument("entity doesn't exit at this index");
    if (isKilled(Entity(idx)))
        throw std::invalid_argument("no alive entity at this at this index (killed)");
    return Entity(idx);
}

void Registry::killEntity(Entity const &e) {
    if (e < _entities && !isKilled(e)) {
        _killedEntities.push_back(e);
        for (auto i : _componentsArrays)
            _destructorArray[i.first](*this, Entity(e));
    }
    if (e >= _entities)
        throw std::invalid_argument("entity doesn't exist");
    if (isKilled(e))
        throw std::invalid_argument("entity already killed");
}

template <typename Component>
typename SparseArray<Component>::reference_type Registry::addComponent(Entity const &to, Component &&c) {
    SparseArray<Component> array = std::any_cast(_componentsArrays[std::type_index(Component)]);
    array.insertAt(to, c);
}

template <typename Component, typename ...Params>
typename SparseArray<Component>::reference_type Registry::emplaceComponent(Entity const &to, Params &&...p) {
    SparseArray<Component> array = std::any_cast(_componentsArrays[std::type_index(Component)]);
    array.emplaceAt(to, p);
}

template <typename Component>
void Registry::removeComponent(Entity const &from) {
    SparseArray<Component> array = std::any_cast(_componentsArrays[std::type_index(Component)]);
    array.erase(from);
}

bool Registry::isKilled(Entity const &e) {
    for (auto i = 0; i < _killedEntities.size(); i++)
        if ((size_t)e == (size_t)_killedEntities[i])
            return true;
    return false;
}
