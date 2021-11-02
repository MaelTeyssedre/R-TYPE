/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** SparseArray
*/

#include "SparseArray.hpp"
#include <stdexcept>
#include <memory>

template <typename Component>
SparseArray<Component>::SparseArray(SparseArray const &sparseArray)
    : _data(sparseArray._data) {}

template <typename Component>
SparseArray<Component>::SparseArray(SparseArray &&sparseArray) noexcept
    : _data(std::move(sparseArray._data)) {}

template <typename Component>
SparseArray<Component> &SparseArray<Component>::operator=(SparseArray const &sparseArray) {
    std::swap(_data, sparseArray._data);
    return *this;
}

template <typename Component>
SparseArray<Component> &SparseArray<Component>::operator=(SparseArray &&sparseArray) noexcept {
    _data = std::move(sparseArray._data);
    return *this;
}

template <typename Component>
SparseArray<Component>::reference_type SparseArray<Component>::operator[](size_t idx) {
    return _data[idx];
}

template <typename Component>
SparseArray<Component>::const_reference_type SparseArray<Component>::operator[](size_t idx) const {
    return _data[idx];
}

template <typename Component>
SparseArray<Component>::iterator SparseArray<Component>::begin() {
    return _data.begin();
}

template <typename Component>
SparseArray<Component>::const_iterator SparseArray<Component>::begin() const {
    return _data.begin();
}

template <typename Component>
SparseArray<Component>::const_iterator SparseArray<Component>::cbegin() const {
    return _data.cbegin();
}

template <typename Component>
SparseArray<Component>::iterator SparseArray<Component>::end() {
    return _data.end();
}

template <typename Component>
SparseArray<Component>::const_iterator SparseArray<Component>::end() const {
    return _data.end();
}

template <typename Component>
SparseArray<Component>::const_iterator SparseArray<Component>::cend() const {
    return _data.cend();
}

template <typename Component>
SparseArray<Component>::size_type SparseArray<Component>::size() const {
    return _data.size();
}

template <typename Component>
SparseArray<Component>::reference_type SparseArray<Component>::insertAt(size_type pos, Component const &component) {
    if (pos > _data.size())
        throw std::invalid_argument("pos superior to SparseArray's size");
    if (pos == _data.size()) {
        _data.push_back(component);
        return _data.back();
    }
    container_t new_container;
    auto i = 0;
    for (; i < pos; i++)
        new_container.push_back(_data[i]);
    new_container.push_back(component);
    for (; i < _data.size(); i++)
        new_container.push_back(_data[i]);
    _data = new_container;
    return _data[pos];
}

template <typename Component>
SparseArray<Component>::reference_type SparseArray<Component>::insertAt(size_type pos, Component &&component) {
    if (pos > _data.size())
        throw std::invalid_argument("pos superior to SparseArray's size");
    if (pos == _data.size()) {
        _data.push_back(std::move(component));
        return _data.back();
    }
    container_t new_container;
    auto i = 0;
    for (; i < pos; i++)
        new_container.push_back(_data[i]);
    new_container.push_back(std::move(component));
    for (; i < _data.size(); i++)
        new_container.push_back(_data[i]);
    _data = new_container;
    return _data[pos];
}


// Je suis pas sur de celle là...
// template <typename Component>
// template <class... Params>
// SparseArray<Component>::reference_type SparseArray<Component>::emplaceAt(size_type pos, Params &&... param) {
//     if (pos >= _data.size())
//         throw std::invalid_argument("pos superior to SparseArray's size");
//     size_t i = 0;
//     for (auto it : _data) {
//         if (i == pos)
//             continue;
//         std::allocator_traits<Component>::destroy();
//         std::allocator_traits<Component>::construct();
//     }
//     return _data[pos];
// }

template <typename Component>
void SparseArray<Component>::erase(size_type pos) {
    container_t new_container;
    if (pos >= _data.size())
        throw std::invalid_argument("pos superior to SparseArray's size");
    for (auto i = 0; i < _data.size(); i++)
        if (pos != i)
            new_container.push_back(_data[i]);
    _data = new_container();
}

template <typename Component>
SparseArray<Component>::size_type SparseArray<Component>::getIndex(value_type const &value) const {
    auto adresse = std::addressof(value);
    for (auto i = 0; i < _data.size(); i++)
        if (adresse == std::addressof(_data[i]))
            return i;
    throw std::invalid_argument("value not found")
}
