/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** SparseArray
*/

#ifndef SPARSEARRAY_HPP_
#define SPARSEARRAY_HPP_

#include <vector>

template <typename Component>

class SparseArray {
    public:
        using value_type = ???;
        using reference_type = value_type &;
        using const_reference_type = value_type const &;
        using container_t = std::vector<value_type>;
        using size_type = typename container_t::size_type;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;

        explicit SparseArray() = default;
        explicit SparseArray(SparseArray const &);
        explicit SparseArray(SparseArray &&) noexcept;

        ~SparseArray() = default;

        SparseArray &operator=(SparseArray const &);
        SparseArray &operator=(SparseArray &&) noexcept;

        reference_type operator[](size_t idx);
        const_reference_type operator[](size_t idx) const;

        iterator begin();
        const_iterator begin() const;
        const_iterator cbegin() const;

        iterator end();
        const_iterator end() const;
        const_iterator cend() const;

        size_type size() const;

        reference_type insertAt(size_type pos, Component const &);
        reference_type insertAt(size_type pos, Component &&);

        // template <class... Params>
        // reference_type emplaceAt(size_type pos, Params &&...);

        void erase(size_type pos);

        size_type getIndex(value_type const &) const;

    private:
        container_t _data;
};

#endif /* !SPARSEARRAY_HPP_ */
