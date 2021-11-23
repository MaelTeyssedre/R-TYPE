/**
 * \file SizeComponent.hpp
 * 
 * \brief file for the size component 
 */

#ifndef SIZECOMPONENT_HPP_
    #define SIZECOMPONENT_HPP_

    #include <iostream>

    /**
     * \namespace components
     * 
     * \brief namespace for ECS components
     * 
     */
    namespace components {

        /**
         * \struct size_s
         * 
         * \brief size component
         * 
         */
        struct size_s {
            size_t width;
            size_t heigth;
        };
    }

#endif /* !SIZECOMPONENT_HPP_ */
