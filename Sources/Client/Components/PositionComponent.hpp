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
             * \struct position_s
             * 
             * \brief the position component
             *
             */
            typedef struct position_s {
                float x; /*!< X position */
                float y; /*!< Y position */
            } position_t;
        }
    }

#endif /* !POSITIONCOMPONENT_HPP_ */
