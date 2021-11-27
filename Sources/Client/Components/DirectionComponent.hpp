/**
 * \file DirectionComponent.hpp
 * 
 * \brief file for the direction component 
 */

#ifndef DIRECTIONCOMPONENT_HPP_
    #define DIRECTIONCOMPONENT_HPP_

    #include <iostream>

    /**
     * \namespace components
     * 
     * \brief namespace for ECS components
     * 
     */
    namespace components {
        /**
         * \struct direction_s
         * 
         * \brief direction component
         * 
         */
        typedef struct direction_s {
            int x;
            int y;
        } direction_t;
    }

#endif /* !DIRECTIONCOMPONENT_HPP_ */
