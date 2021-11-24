/**
 * \file HealthComponent.hpp
 * 
 * \brief file for the health component 
 */

#ifndef HEALTHCOMPONENT_HPP_
    #define HEALTHCOMPONENT_HPP_

    #include <iostream>

    /**
     * \namespace components
     * 
     * \brief namespace for ECS components
     * 
     */
    namespace components {
        typedef struct health_s {
            size_t health;
        } health_t;
    }

#endif /* !HEALTHCOMPONENT_HPP_ */
