/**
 * \file UpdateTime.hpp
 *
 * \brief file where the update time system is defined
 */

#ifndef UPDATETIME_HPP_
    #define UPDATETIME_HPP_

    #include "Registry.hpp"
    #include <chrono>
    #include "Constants.hpp"
    #include "TimeComponent.hpp"

    /**
     * \class UpdateTime UpdateTime.hpp 
     * 
     * \brief class that contain the system UpdateTime
     */
    class UpdateTime {
        public:
            /**
             * \fn explicit UpdateTime() = default
             *
             * \brief ctor UpdateTime
             */
            explicit UpdateTime() = default;

            /**
             * \fn virtual ~UpdateTime() = default
             *
             * \brief dtor UpdateTime
             */
            virtual ~UpdateTime() = default;
            void operator()(Registry &r, SparseArray<components::myTime_s> &times);
        private:
            std::chrono::nanoseconds _currentDeltaTime; /*! The current delta time*/
    };

#endif /* !UPDATETIME_HPP_ */
