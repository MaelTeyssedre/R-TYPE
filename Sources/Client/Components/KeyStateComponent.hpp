/**
 * \file KeyStateComponent.hpp
 * 
 * \brief file for the Key state component 
 */
#ifndef KEYSTATECOMPONENT_HPP_
    #define KEYSTATECOMPONENT_HPP_

    #include <iostream>

    /**
     * \namespace components
     * 
     * \brief namespace for ECS components
     * 
     */
    namespace components {
        /**
         * \struct keyState_s
         * 
         * \brief key state component
         * 
         */
        typedef struct keyState_s {
            bool keyUp;
            bool keyDown;
            bool keyRight;
            bool keyLeft;
            bool keyEnter;
            bool keySpace;
        } keyState_t;
    }

#endif /* !KEYSTATECOMPONENT_HPP_ */
