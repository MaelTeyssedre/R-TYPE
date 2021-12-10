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
             * \struct myTime_s
             * 
             * \brief the time component
             *
             */
            typedef struct myTime_s {
                std::chrono::nanoseconds deltaTime; /*!< time elapsed */
            } myTime_t;
        }
    }

#endif /* !TIMECOMPONENT_HPP_ */
