/**
 * \file Zipper.hpp
 *
 * \brief file where the Zipper class is defined
 */

#ifndef ZIPPER_HPP_
#define ZIPPER_HPP_

#include "ZipperIterator.hpp"
#include <algorithm>

    /**
     * \class Zipper Zipper.hpp
     * 
     * \brief Zipper of the ECS
     */
    template <class ...Containers>
    class Zipper {
        public:
            using iterator = ZipperIterator<Containers...>;
            using iterator_tuple = typename iterator::iterator_tuple;
            
            /**
             * \fn Zipper(Containers &... cs)
             * 
             * \brief ctor which take a reference of a variadic Containers object
             * 
             * \param cs reference to a list of Containers object
             */
            Zipper(Containers &... cs)
                : _size(0) {
                _computeSize(cs...);
                _computeEnd(cs...);
                _computeBegin(cs...);
            };

            /**
             * \fn iterator begin()
             * 
             * \brief go to the beginning of the Containers object
             */
            iterator begin() {
                return iterator(_begin, _size);
            }

            /**
             * \fn iterator end()
             * 
             * \brief go to the end of the Containers object
             */
            iterator end() {
                return iterator(_end, 0);
            }

        private:
            /**
             * \fn void _computeSize(Containers &... containers)
             * 
             * \brief calculate the size of the shortest maximal size
             * 
             * \param containers reference to a variadic Containers object
             */
            void _computeSize(Containers &... containers) {
                _size = std::min({(containers.size())...});
            }

            /**
             * \fn void _computeBegin(Containers &... containers)
             * 
             * \brief calculate the first tuple iterator tuple position
             * 
             * \param containers reference to a variadic Containers object
             */
            void _computeBegin(Containers &... containers) {
                _begin = std::tie((containers.begin())...);
            }

            /**
             * \fn void _computeEnd(Containers &... containers)
             * 
             * \brief calculate the last tuple iterator tuple position
             * 
             * \param containers reference to a variadic Containers object
             */
            void _computeEnd(Containers &... containers) {
                _end = std::tie((containers.begin() + _size)...);
            }
        
        private:
            iterator_tuple _begin; /*! first iterator on the element tuple */
            iterator_tuple _end; /*! last iterator on the element tuple */
            size_t _size; /*! size of the shortest maximal size */
    };

#endif /* !ZIPPER_HPP_ */
