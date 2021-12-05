/**
 * \file TimeComponent.hpp
 * 
 * \brief file for the time component 
 */

#ifndef TIMECOMPONENT_HPP_
    #define TIMECOMPONENT_HPP_

    #include <chrono>

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
             * \struct myTime_s
             * 
             * \brief the time component
             * 
             */
            struct myTime_s {
                std::chrono::nanoseconds deltaTime;
            };
        }
    }

#endif /* !TIMECOMPONENT_HPP_ */
