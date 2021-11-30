/**
 * \file PositionComponent.hpp
 * 
 * \brief file for the position component 
 */

#ifndef POSITIONCOMPONENT_HPP_
    #define POSITIONCOMPONENT_HPP_

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
             * \struct position_s
             * 
             * \brief position component
             *
             */
            struct position_s {
                float x; /*!< the x position */
                float y; /*!< the y position */
            };
        }
    }

#endif /* !POSITIONCOMPONENT_HPP_ */
