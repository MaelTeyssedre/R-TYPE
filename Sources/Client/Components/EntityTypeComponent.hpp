/**
 * \file EntityTypeComponent.hpp
 * 
 * \brief file for the entity type component 
 */

#ifndef ENTITYTYPECOMPONENT_HPP_
    #define ENTITYTYPECOMPONENT_HPP_

    #include <iostream>
    #include "Constants.hpp"

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
             * \struct entityType_s
             * 
             * \brief entityType component
             *
             */
            struct entityType_s {
                rtype::constants::ENTITY_TYPE entityType; /*!< The entity type */
            };
        }
    }

#endif /* !ENTITYTYPECOMPONENT_HPP_ */
