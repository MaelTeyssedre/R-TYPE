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
             * \struct mouseState_s
             * 
             * \brief the mouseState component
             *
             */
            struct mouseState_s {
                int mousePosX; /*!< mouse X position */
                int mousePosY; /*!< mouse Y position */
                bool mouseRightClick; /*!< status of the right click */
                bool mouseLeftClick; /*!< status of the left click */
            };
        }
    }

#endif /* !MOUSESTATECOMPONENT_HPP_ */
