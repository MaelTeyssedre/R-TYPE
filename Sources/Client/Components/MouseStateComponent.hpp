/**
 * \file MouseStateComponent.hpp
 * 
 * \brief file for the mouse state component 
 */
#ifndef MOUSESTATECOMPONENT_HPP_
    #define MOUSESTATECOMPONENT_HPP_

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
             * \struct mouseState_s
             * 
             * \brief mouse state component
             *
             */
            struct mouseState_s {
                int mousePosX; /*!< The mouse x position */
                int mousePosY; /*!< The mouse y position */
                bool mouseRightClick; /*!< To check if a right mouse click append */
                bool mouseLeftClick; /*!< To check if a left mouse click append */
            };
        }
    }

#endif /* !MOUSESTATECOMPONENT_HPP_ */
