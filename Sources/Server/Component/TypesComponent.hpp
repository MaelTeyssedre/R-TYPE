/**
 * \file TypesComponent.hpp
 *
 * \brief file for the types component
 */

#ifndef TYPESCOMPONENT_HPP_
#define TYPESCOMPONENT_HPP_

#include "Components.hpp"

 /**
 * \namespace rtype
 *
 * \brief namespace for the R-Type
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
         * \struct types_s
         *
         * \brief the type component
         *
         */
        struct types_s {
            enum TYPES;
        };
    }
}

#endif /* !TIMECOMPONENT_HPP_ */
