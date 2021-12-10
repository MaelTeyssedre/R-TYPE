/**
 * \file Velocity.hpp
 * 
 * \brief file for the velocity component 
 */

#ifndef VELOCITY_HPP_
    #define VELOCITY_HPP_

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
             * \struct velocity_s
             * 
             * \brief velocity component
             * 
             */
            typedef struct velocity_s {
                int vx;
                int vy;
            } velocity_t;
        }
    }

#endif /* !VELOCITY_HPP_ */
