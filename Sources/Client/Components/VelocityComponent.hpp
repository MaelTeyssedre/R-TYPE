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
     * \brief namespace forthe R-Type
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
            struct velocity_s {
                size_t x; /*!< X movement speed */
                size_t y; /*!< Y movement speed */
            };
        }
    }

#endif /* !VELOCITYCOMPONENT_HPP_ */
