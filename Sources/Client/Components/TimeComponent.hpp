#ifndef TIMECOMPONENT_HPP_
    #define TIMECOMPONENT_HPP_

    #include <chrono>

    namespace components {
        typedef struct myTime_s {
            std::chrono::nanoseconds deltaTime;
        } myTime_t;
    }

#endif /* !TIMECOMPONENT_HPP_ */
