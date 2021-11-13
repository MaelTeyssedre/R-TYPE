#ifndef SPARSEARRAY_HPP_
    #define SPARSEARRAY_HPP_

    #include <vector>
    #include <iostream>
    #include <memory>
    #include <optional>
    #include <type_traits>

    template <typename Component>
    class SparseArray
    {
        public:
            using value_type = std::optional<Component>;
            using reference_type = value_type &;
            using const_reference_type = value_type const &;
            using container_t = std::vector<value_type>;
            using size_type = typename container_t::size_type;
            using iterator = typename container_t::iterator;
            using const_iterator = typename container_t::const_iterator;
        public:
            /*!
             * \brief Default ctor
             */
            SparseArray() = default;

            /*!
             * \brief copy ctor
             *
             * \param sparceArray Constante reference to the SparseArray that will be copied
             */
            SparseArray(SparseArray const &sparceArray) {
                for (size_t i = 0; i < sparceArray.size(); i++)
                    _data.push_back(std::nullopt);
                for (size_t i = 0; i < sparceArray.size(); i++)
                    _data[i] = sparceArray._data[i];
                
            };

            /*!
             * \brief Move Ctor
             * 
             * \param sparseArray Universal reference to the SparseArray that will be moved
             */
            SparseArray(SparseArray &&sparseArray) noexcept
                : _data(std::move(sparseArray._data)) {}

            /*!
             * \brief Ctor that generate a number of entity by default
             * 
             * \param nbEntity number of entity to create
             */
            SparseArray(size_t nbEntity) {
                for (size_t i = 0; i < nbEntity; i++)
                    _data.push_back(std::nullopt);
            }

            /*!
             * \brief Default dtor
             */
            ~SparseArray() = default;

            /*!
             * \brief Extend the number of entity
             *
             * \param size number of entity to add
             */
            void extend(size_t size) {
                for (auto i = 0; i < size; i++)
                    _data.push_back(std::nullopt);
            }

            /*!
             * \brief copy assignation operator
             *
             * \param sparseArray Contante reference to the SparseArray that will be assigned to another
             * 
             * \return Reference to the assigned SparseArray
             */
            SparseArray &operator=(SparseArray const &sparseArray) {
                std::swap(_data, sparseArray._data);
                return *this;
            }

            /*!
             * \brief move assignation operator
             *
             * \param sparseArray Contante reference to the SparseArray that will be moved into another
             * 
             * \return Reference to the assigned SparseArray
             */
            SparseArray &operator=(SparseArray &&sparceArray) noexcept {
                _data = std::move(sparseArray._data);
                return *this;
            }

            /*!
             * \brief 
             */
            reference_type operator[](size_t idx) {
                return _data[idx];
            }

            /*!
             * \brief bracket operator
             *
             * \param idx index to return
             * 
             * \return constant reference to the value at the index passed in parameter
             */
            const_reference_type operator[](size_t idx) const {
                return _data[idx];
            }

            /*!
             * \brief getter for the first element
             *
             * \return iterator to the first element
             */
            iterator begin() {
                return _data.begin();
            }

            /*!
             * \brief getter for the first element
             *
             * \return constant iterator to the first element
             */
            const_iterator begin() const {
                return _data.begin();
            }

            /*!
             * \brief 
             */
            const_iterator cbegin() const {
                return _data.cbegin();
            }

            /*!
             * \brief getter for the last element
             *
             * \return iterator to the last element
             */
            iterator end() {
                return _data.end();
            }

            /*!
             * \brief getter for the last element
             *
             * \return constant iterator to the last element
             */
            const_iterator end() const {
                return _data.end();
            }

            /*!
             * \brief
             */
            const_iterator cend() const {
                return _data.cend();
            }

            /*!
             * \brief getter for the size of the array
             *
             * \return size of the array
             */
            size_type size() const {
                return _data.size();
            }

            /*!
             * \brief add an element to an index (entity), erase the current if it exist
             *
             * \param pos position where to insert the component
             * \param component constant reference to the component to add
             * 
             * \return reference to the inserted component
             */
            reference_type insertAt(size_type pos, Component const &component) {
                if (pos > _data.size())
                    throw std::invalid_argument("pos superior to SparseArray's size");
                if (pos == _data.size()) {
                    _data.push_back(component);
                    return _data.back();
                }
                auto alloc = _data.get_allocator();
                std::allocator_traits<decltype(alloc)>::destroy(alloc, std::addressof(_data[pos]));
                _data[pos] = component;
                return _data[pos];
            }

            /*!
             * \brief move an element to an index (entity), erase the current if it exist
             *
             * \param pos position where to move the component
             * \param component universal reference to the component to move
             * 
             * \return reference to the moved component
             */
            reference_type insertAt(size_type pos, Component &&component) {
                if (pos > _data.size())
                    throw std::invalid_argument("pos superior to SparseArray's size");
                if (pos == _data.size()) {
                    _data.push_back(std::move(component));
                    return _data.back();
                }
                auto alloc = _data.get_allocator();
                std::allocator_traits<decltype(alloc)>::destroy(alloc, std::addressof(_data[pos]));
                _data[pos] = std::move(component);
                return _data[pos];
            }

            /*!
             * \brief create an element to an index (entity), erase the current if it exist
             *
             * \param pos position where to create the component
             * \param component universal reference of a template variadic of arguments to create the component
             * 
             * \return reference to the created component
             */
            template <class... Params>
            reference_type emplaceAt(size_type pos, Params &&...params) {
                if (pos >= _data.size())
                    throw std::invalid_argument("pos superior to SparseArray's size");
                auto alloc = _data.get_allocator();
                std::allocator_traits<decltype(alloc)>::destroy(alloc, std::addressof(_data[pos]));
                std::allocator_traits<decltype(alloc)>::construct(alloc, std::addressof(_data[pos]), std::forward(params)...);
                return _data[pos];
            }

            /*!
             * \brief erase a component a the specified index
             *
             * \param pos index of the component to erase
             */
            void erase(size_type pos) {
                if (pos >= _data.size())
                    throw std::invalid_argument("pos superior to SparseArray's size");
                auto alloc = _data.get_allocator();
                std::allocator_traits<decltype(alloc)>::destroy(alloc, std::addressof(_data[pos]));
            }

            /*!
             * \brief getter for the index of an entity
             * 
             * \param value constant reference to an antity by his value
             * 
             * \return index of the value (entity)
             */
            size_type getIndex(value_type const &value) const {
                auto adresse = std::addressof(value);
                for (auto i = 0; i < _data.size(); i++)
                    if (adresse == std::addressof(_data[i]))
                        return i;
                throw std::invalid_argument("value not found")
            }
        private:
            container_t _data; /*! Array of optional component */
    };

#endif /* !SPARSEARRAY_HPP_ */
