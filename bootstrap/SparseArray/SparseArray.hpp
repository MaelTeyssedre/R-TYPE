/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** SparseArray
*/

#ifndef SPARSEARRAY_HPP_
#define SPARSEARRAY_HPP_

#include <vector>
#include <iostream>
#include <memory>
#include <type_traits>

template <typename Component>
class SparseArray
{
    public:
        using value_type = ???;
        using reference_type = value_type &;
        using const_reference_type = value_type const &;
        using container_t = std::vector<value_type>;
        using size_type = typename container_t::size_type;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;

        explicit SparseArray() = default;
        explicit SparseArray(SparseArray const &sparceArray)
            : _data(sparseArray._data) {}
        explicit SparseArray(SparseArray &&sparseArray) noexcept
            : _data(std::move(sparseArray._data)) {}

        ~SparseArray() = default;

        SparseArray &operator=(SparseArray const &sparseArray) {
            std::swap(_data, sparseArray._data);
            return *this;
        }

        SparseArray &operator=(SparseArray &&sparceArray) noexcept {
            _data = std::move(sparseArray._data);
            return *this;
        }

        reference_type operator[](size_t idx) {
            return _data[idx];
        }

        const_reference_type operator[](size_t idx) const {
            return _data[idx];
        }

        iterator begin() {
            return _data.begin();
        }

        const_iterator begin() const {
            return _data.begin();
        }

        const_iterator cbegin() const {
            return _data.cbegin();
        }

        iterator end() {
            return _data.end();
        }

        const_iterator end() const {
            return _data.end();
        }

        const_iterator cend() const {
            return _data.cend();
        }

        size_type size() const {
            return _data.size();
        }

        reference_type insertAt(size_type pos, Component const &component) {
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

        reference_type insertAt(size_type pos, Component &&component) {
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

        template <class... Params>
        reference_type emplaceAt(size_type pos, Params &&...params) {
            if (pos >= _data.size())
                throw std::invalid_argument("pos superior to SparseArray's size");
            auto alloc = _data.get_allocator();
            std::allocator_traits<decltype(alloc)>::destroy(alloc, std::addressof(_data[pos]));
            std::allocator_traits<decltype(alloc)>::construct(alloc, std::addressof(_data[pos]), std::forward(params)...);
            return _data[pos];
        }

        void erase(size_type pos) {
            container_t new_container;
            if (pos >= _data.size())
                throw std::invalid_argument("pos superior to SparseArray's size");
            for (auto i = 0; i < _data.size(); i++)
                if (pos != i)
                    new_container.push_back(_data[i]);
            _data = new_container();
        }

        size_type getIndex(value_type const &value) const {
            auto adresse = std::addressof(value);
            for (auto i = 0; i < _data.size(); i++)
                if (adresse == std::addressof(_data[i]))
                    return i;
            throw std::invalid_argument("value not found")
        }

    private:
        container_t _data;
};

#endif /* !SPARSEARRAY_HPP_ */
