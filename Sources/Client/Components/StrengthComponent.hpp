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
             * \struct strength_s
             * 
             * \brief the strength component
             *
             */
            struct strength_s {
                size_t strength; /*! The strength statistic */
            };
        }
    }

#endif /* !STRENGTHCOMPONENT_HPP_ */
