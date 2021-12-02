#ifndef ZIPPER_HPP_
#define ZIPPER_HPP_

#include "ZipperIterator.hpp"
#include <algorithm>

    template <class ...Containers>
    class Zipper {
        public:
            using iterator = ZipperIterator<Containers...>;
            using iterator_tuple = typename iterator::iterator_tuple;
            
            Zipper(Containers &... cs)
                : _size(0) {
                _computeSize(cs...);
                _computeEnd(cs...);
                _computeBegin(cs...);
            };

            auto begin() -> iterator {
                return iterator(_begin, _size);
            }
            auto end() -> iterator {
                return iterator(_end, 0);
            }

        private:
            auto _computeSize(Containers &... containers) -> void {
                _size = std::min({(containers.size())...});
            }

            auto _computeBegin(Containers &... containers) -> void {
                _begin = std::tie((containers.begin())...);
            }

            auto _computeEnd(Containers &... containers) -> void {
                _end = std::tie((containers.begin() + _size)...);
            }
        
        private:
            iterator_tuple _begin;
            iterator_tuple _end;
            size_t _size;
    };

#endif /* !ZIPPER_HPP_ */
