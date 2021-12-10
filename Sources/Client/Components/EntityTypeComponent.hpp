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
             * \struct entityType_s
             * 
             * \brief the entityType component
             *
             */
            typedef struct entityType_s {
                rtype::constants::ENTITY_TYPE entityType;  /*!< type of the entity */
            } entityType_t;
        }
    }

#endif /* !ENTITYTYPECOMPONENT_HPP_ */
