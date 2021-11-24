/**
 * \file TimeComponent.hpp
 * 
 * \brief file for the time component 
 */

#ifndef TIMECOMPONENT_HPP_
    #define TIMECOMPONENT_HPP_

    #include <chrono>

    /**
     * \namespace components
     * 
     * \brief namespace for ECS components
     * 
     */
    namespace components {
        typedef struct myTime_s {
            std::chrono::nanoseconds deltaTime;
        } myTime_t;
    }

#endif /* !TIMECOMPONENT_HPP_ */
