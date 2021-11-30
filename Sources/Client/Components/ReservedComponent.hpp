/**
 * \file ReservedComponent.hpp
 * 
 * \brief file for the reserved component 
 */

#ifndef RESERVEDCOMPONENT_HPP_
    #define RESERVEDCOMPONENT_HPP_

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
             * \struct reserved_s
             * 
             * \brief reserved component
             *
             */
            struct reserved_s {
                bool reserved; /*!< To check if it is reserved */
            };
        }
    }

#endif /* !RESERVEDCOMPONENT_HPP_ */
