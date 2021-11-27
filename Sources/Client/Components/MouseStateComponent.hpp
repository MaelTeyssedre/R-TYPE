/**
 * \file MouseStateComponent.hpp
 * 
 * \brief file for the mouse state component 
 */
#ifndef MOUSESTATECOMPONENT_HPP_
    #define MOUSESTATECOMPONENT_HPP_

    #include <iostream>

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
        typedef struct mouseState_s {
            int mousePosX;
            int mousePosY;
            bool mouseRightClick;
            bool mouseLeftClick;
        } mouseState_t;
    }

#endif /* !MOUSESTATECOMPONENT_HPP_ */
