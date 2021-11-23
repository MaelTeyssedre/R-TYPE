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
            rtype::constants::ENTITY_TYPE entityType; 
        };
    }

#endif /* !ENTITYTYPECOMPONENT_HPP_ */