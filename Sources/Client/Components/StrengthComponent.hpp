/**
 * \file StrengthComponent.hpp
 * 
 * \brief file for the strength component 
 */

#ifndef STRENGTHCOMPONENT_HPP_
    #define STRENGTHCOMPONENT_HPP_

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
             * \struct strength_s
             * 
             * \brief the strength component
             *
             */
            struct strength_s {
                size_t strength; /*!< Strength of the object */
            };
        }
    }

#endif /* !STRENGTHCOMPONENT_HPP_ */
