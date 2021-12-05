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
            struct velocity_s {
                int vx;
                int vy;
            };
        }
    }

#endif /* !VELOCITY_HPP_ */
