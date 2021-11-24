/**
 * \file StrengthComponent.hpp
 * 
 * \brief file for the strength component 
 */

#ifndef STRENGTHCOMPONENT_HPP_
    #define STRENGTHCOMPONENT_HPP_

    #include <iostream>

    /**
     * \namespace components
     * 
     * \brief namespace for ECS components
     * 
     */
    namespace components {
        typedef struct strength_s {
            size_t strength;
        } strength_t;
    }

#endif /* !STRENGTHCOMPONENT_HPP_ */
