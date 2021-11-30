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
             * \struct keyState_s
             * 
             * \brief key state component
             *
             */
            struct keyState_s {
                bool keyUp; /*!< The up key */
                bool keyDown; /*!< The down key */
                bool keyRight; /*!< The right key */
                bool keyLeft; /*!< The left key */
                bool keyEnter; /*!< The enter key */
                bool keySpace; /*!< The space key */
            };
        }
    }

#endif /* !KEYSTATECOMPONENT_HPP_ */
