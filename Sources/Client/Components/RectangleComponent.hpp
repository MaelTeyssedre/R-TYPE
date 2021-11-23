
#ifndef RECTANGLECOMPONENT_HPP_
    #define RECTANGLECOMPONENT_HPP_

    #include <iostream>
    #include "SizeComponent.hpp"
    #include "PositionComponent.hpp"

    namespace components {
        struct rectangle_s {
            size_t x;
            size_t y;
            size_t width;
            size_t heigth;
        };
    }

#endif /* !RECTANGLECOMPONENT_HPP_ */
