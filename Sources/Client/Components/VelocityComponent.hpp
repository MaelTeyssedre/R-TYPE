/**
 * \file VelocityComponent.hpp
 * 
 * \brief file for the velocity component 
 */

#ifndef VELOCITYCOMPONENT_HPP_
    #define VELOCITYCOMPONENT_HPP_

    #include <iostream>

    /**
     * \namespace rtype
     * 
     * \brief namespace for rtype project
     * 
     */
    namespace rtype {
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
             * \brief the velocity component
             *
             */
            typedef struct velocity_s {
                size_t x; /*!< x velocity */
                size_t y; /*!< y velocity */
            } velocity_t;
        }
    }

#endif /* !VELOCITYCOMPONENT_HPP_ */
