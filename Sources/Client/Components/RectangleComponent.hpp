
#ifndef RECTANGLECOMPONENT_HPP_
    #define RECTANGLECOMPONENT_HPP_

    #include <iostream>
    #include "SizeComponent.hpp"
    #include "PositionComponent.hpp"

    namespace components {
        struct rectangle_s {
            struct position_s position;
            struct size_s size;
        };
    }

#endif /* !RECTANGLECOMPONENT_HPP_ */
