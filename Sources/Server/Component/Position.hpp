/**
 * \file Position.hpp
 * 
 * \brief file for position component 
 */

#ifndef POSITION_HPP_
    #define POSITION_HPP_

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
             * \struct position_s
             * 
             * \brief position component
             * 
             */
            typedef struct position_s {
                int x;
                int y;
            } position_t;
        }
    }

#endif /* !POSITION_HPP_ */
