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
             * \struct reserved_s
             * 
             * \brief the reserved component
             *
             */
            struct reserved_s {
                bool reserved; /*!< Is this id reserved */
            };
        }
    }

#endif /* !RESERVEDCOMPONENT_HPP_ */
