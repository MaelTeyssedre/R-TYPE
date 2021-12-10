/**
 * \file KeyStateComponent.hpp
 * 
 * \brief file for the Key state component 
 */

#ifndef KEYSTATECOMPONENT_HPP_
    #define KEYSTATECOMPONENT_HPP_

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
             * \struct keyState_s
             * 
             * \brief the keyState component
             *
             */
            typedef struct keyState_s {
                bool keyUp; /*!< status of the keyUp */
                bool keyDown; /*!< status of the keyDown */
                bool keyRight; /*!< status of the keyRight */
                bool keyLeft; /*!< status of the keyLeft */
                bool keyEnter; /*!< status of the keyEnter */
                bool keySpace; /*!< status of the keySpace */
            } keyState_t;
        }
    }

#endif /* !KEYSTATECOMPONENT_HPP_ */
