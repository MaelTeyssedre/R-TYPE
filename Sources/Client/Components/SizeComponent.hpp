/**
 * \file SizeComponent.hpp
 * 
 * \brief file for the size component 
 */

#ifndef SIZECOMPONENT_HPP_
    #define SIZECOMPONENT_HPP_

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
             * \struct mySize_s
             * 
             * \brief the size component
             *
             */
            struct mySize_s {
                size_t width; /*!< The width */
                size_t heigth; /*!< The heigth */
            };
        }
    }

#endif /* !SIZECOMPONENT_HPP_ */
