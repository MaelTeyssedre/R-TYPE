/**
 * \file PositionComponent.hpp
 * 
 * \brief file for the position component 
 */

#ifndef POSITIONCOMPONENT_HPP_
    #define POSITIONCOMPONENT_HPP_

    #include <iostream>

    /**
     * \namespace components
     * 
     * \brief namespace for ECS components
     * 
     */
    namespace components {
        /**
         * \struct position_s
         * 
         * \brief position component
         * 
         */
        typedef struct position_s {
            float x;
            float y;
        } position_t;
    }

#endif /* !POSITIONCOMPONENT_HPP_ */
