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
     * \brief namespace for the R-Type
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
             * \brief direction component
             *
             */
            struct direction_s {
                int x; /*!< the x direction */
                int y; /*!< the y direction */
            };
        }
    }

#endif /* !DIRECTIONCOMPONENT_HPP_ */
