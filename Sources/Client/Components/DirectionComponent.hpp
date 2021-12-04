/**
 * \file DirectionComponent.hpp
 * 
 * \brief file for the direction component 
 */

#ifndef DIRECTIONCOMPONENT_HPP_
    #define DIRECTIONCOMPONENT_HPP_

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
             * \struct direction_s
             * 
             * \brief the direction component
             *
             */
            struct direction_s {
                int x; /*!< x direction */
                int y; /*!< y direction */
            };
        }
    }

#endif /* !DIRECTIONCOMPONENT_HPP_ */
