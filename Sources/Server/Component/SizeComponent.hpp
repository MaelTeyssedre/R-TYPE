/**
 * \file Position.hpp
 * 
 * \brief file for position component 
 */

#ifndef SIZECOMPONENT_HPP_
    #define SIZECOMPONENT_HPP_

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
             * \struct size_s
             * 
             * \brief size component
             * 
             */
            typedef struct size_s {
                int width;
                int height;
            } size_t;
        }
    }

#endif /* !SIZECOMPONENT_HPP_ */
