/**
 * \file HealPoint.hpp
 * 
 * \brief file for HealPoint component 
 */

#ifndef HEALPOINT_HPP_
    #define HEALPOINT_HPP_

    #include <iostream>
    
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
             * \struct healPoint_s
             * 
             * \brief healPoint component
             * 
             */
            typedef struct healPoint_s {
                size_t healPoint;
            } healPoint_t;
        }
    }

#endif /* !HEALPOINT_HPP_ */
