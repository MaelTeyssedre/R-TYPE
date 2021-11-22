#ifndef TIMECOMPONENT_HPP_
#define TIMECOMPONENT_HPP_

#include <chrono>

namespace components {
    struct time_s {
        std::chrono::nanoseconds deltaTime;
    };
}

#endif /* !TIMECOMPONENT_HPP_ */
