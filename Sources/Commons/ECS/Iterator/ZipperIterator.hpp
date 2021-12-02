/**
 * \file ZipperIterator.hpp
 *
 * \brief file where the Zipper Iterator class is defined
 */

#ifndef ZIPPERITERATOR_HPP_
#define ZIPPERITERATOR_HPP_

    #include <iterator>
    #include <utility>
    #include <vector>

    /**
     * \class Zipper ZipperIterator.hpp
     * 
     * \brief \brief declaration of class Zipper to avoid circular includes...
     */
    template <class ...Containers> class Zipper;

    /**
     * \class ZipperIterator ZipperIterator.hpp
     * 
     * \brief \brief declaration of class Zipper to avoid circular includes...
     */
    template <class ...Containers>
    class ZipperIterator {
        template <class Container>
        using iterator_t = decltype(std::declval<Container>().begin());

        template <class Container>
        using it_reference_t = typename iterator_t<Container>::reference;

        public:
            using value_type = std::tuple<decltype(std::declval<it_reference_t<Containers>>().value())&...>;
            using reference = value_type;
            using pointer = void;
            using difference_type = size_t;
            using iterator_category = std::input_iterator_tag;
            using iterator_tuple = std::tuple<iterator_t<Containers>...>;

            /**
             * \fn ZipperIterator(iterator_tuple const &it_tuple, size_t max) 
             * 
             * \brief ctor which take a reference of a iterator tuple with his max size
             * 
             * \param it_tuple reference to an iterator tuple object
             * 
             * \param max max size of the iterator tuple
             */
            friend Zipper<Containers...>;
            ZipperIterator(iterator_tuple const &it_tuple, size_t max) 
                : _current(it_tuple), _max(max), _idx(0) {
                if (!allSet(_seq))
                    incrAll(_seq);
            }

        public:
            /**
             * \fn ZipperIterator(ZipperIterator const &z)
             * 
             * \brief copy ctor
             * 
             * \param z reference to a ZipperIterator object about to be copied
             */
            ZipperIterator(ZipperIterator const &z)
                : _current(z._current), _max(z._max), _idx(z._idx) {}

            /**
             * \fn ZipperIterator operator++()
             * 
             * \brief operator ++ overload
             * 
             * \return A ZipperIterator affected by the overloaded operator
             */
            ZipperIterator operator++() {
                incrAll(_seq);
                return *this;
            }

            /**
             * \fn ZipperIterator &operator++(int)
             * 
             * \brief operator ++ overload
             * 
             * \param int why ?
             * 
             * \return A reference to the ZipperIterator affected by the overloaded operator
             */
            ZipperIterator &operator++(int) {
                auto cpy = *this;
                incrAll(_seq);
                return cpy;
            }

            /**
             * \fn value_type operator*()
             * 
             * \brief operator * overload
             * 
             * \return A value_type affected by the overloaded operator
             */
            value_type operator*() {
                return toValue(_seq);
            }

            /**
             * \fn value_type operator->()
             * 
             * \brief operator -> overload
             * 
             * \return A value_type affected by the overloaded operator
             */
            value_type operator->() {
                return toValue(_seq);
            }

            /**
             * \fn friend bool operator==(ZipperIterator const &lhs, ZipperIterator const &rhs)
             * 
             * \brief operator == overload
             * 
             * \param lhs reference to the left hand side of the operator
             * 
             * \param rhs reference to the right hand side of the operator
             * 
             * \return true if lhs and rhs are equals, false otherwise
             */
            friend bool operator==(ZipperIterator const &lhs, ZipperIterator const &rhs) {
                return lhs._current == rhs._current;
            }

            /**
             * \fn friend bool operator!=(ZipperIterator const &lhs, ZipperIterator const &rhs)
             * 
             * \brief operator != overload
             * 
             * \param lhs reference to the left hand side of the operator
             * 
             * \param rhs reference to the right hand side of the operator
             * 
             * \return true if lhs and rhs aren't equals, false otherwise
             */
            friend bool operator!=(ZipperIterator const &lhs, ZipperIterator const &rhs) {
                return lhs._current != rhs._current;
            }

        private:
            /**
             * \fn void incrAll(std::index_sequence<Is...>)
             * 
             * \brief increase the iterator tuple by the given index
             * 
             * \param index_sequence a variadic index
             */
            template <size_t ...Is>
            void incrAll(std::index_sequence<Is...>) {
                for (; _idx < _max && allSet(_seq); _idx++)
                    ((++(std::get<Is>(_current))), ...);
            }

            /**
             * \fn bool allSet(std::index_sequence<Is...>)
             * 
             * \brief move the iterator tuple to the given index
             * 
             * \param index_sequence a variadic index
             * 
             * \return true and i want to die just what the hell is this and the adress of the extracted current iterator tuple
             */
            template <size_t ...Is>
            bool allSet(std::index_sequence<Is...>) {
                return (true && ... && *std::get<Is>(_current));
            }

            /**
             * \fn value_type toValue(std::index_sequence<Is...>)
             * 
             * \brief move the iterator tuple to the given value
             * 
             * \param index_sequence a variadic index
             * 
             * \return the value extracted of the iterator tuple
             */
            template <size_t ...Is>
            value_type toValue(std::index_sequence<Is...>) {
                return std::tie((*std::get<Is>(_current)).value()...);
            }

        private:
            iterator_tuple _current; /*! The current iterator tuple content */
            size_t _max; /*! size of the shortest maximal size */
            size_t _idx; /*! The current iterator tuple position */

            static constexpr std::index_sequence_for<Containers ...> _seq{}; /*! A world of pain */
    };

#endif /* !ZIPPERITERATOR_HPP_ */
