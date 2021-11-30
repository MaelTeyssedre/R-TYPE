/**
 * \file HealthComponent.hpp
 * 
 * \brief file for the health component 
 */

#ifndef HEALTHCOMPONENT_HPP_
    #define HEALTHCOMPONENT_HPP_

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
             * \struct health_s
             * 
             * \brief health component
             *
             */
            struct health_s {
                size_t health; /*!< The health statistic */
            };
        }
    }

#endif /* !HEALTHCOMPONENT_HPP_ */
