/**
 * \file IndexComponent.hpp
 * 
 * \brief file for the Index component 
 */

#ifndef INDEXCOMPONENT_HPP_
#define INDEXCOMPONENT_HPP_

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
             * \struct index_s
             * 
             * \brief the index component
             *
             */
            typedef struct index_s {
                size_t idx; /*!< index of the object */
            } index_t;
        }
    }

#endif /* !INDEXCOMPONENT_HPP_ */
