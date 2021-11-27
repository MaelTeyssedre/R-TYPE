/**
 * \file VelocityComponent.hpp
 * 
 * \brief file for the velocity component 
 */

#ifndef VELOCITYCOMPONENT_HPP_
    #define VELOCITYCOMPONENT_HPP_

    #include <iostream>

    /**
     * \namespace components
     * 
     * \brief namespace for ECS components
     * 
     */
    namespace components {
        /**
         * \struct velocity_s
         * 
         * \brief velocity component
         * 
         */
        typedef struct velocity_s {
            size_t x;
            size_t y;
        } velocity_t;
    }

#endif /* !VELOCITYCOMPONENT_HPP_ */
