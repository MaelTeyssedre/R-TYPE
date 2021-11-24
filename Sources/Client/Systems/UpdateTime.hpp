#ifndef UPDATETIME_HPP_
    #define UPDATETIME_HPP_

    #include "Registry.hpp"
    #include <chrono>
    #include "Constants.hpp"
    #include "TimeComponent.hpp"

    class UpdateTime {
        public:
            explicit UpdateTime() = default;
            virtual ~UpdateTime() = default;
            void operator()(Registry &r, SparseArray<components::myTime_s> &times);
        private:
            std::chrono::nanoseconds _currentDeltaTime;
    };

#endif /* !UPDATETIME_HPP_ */
