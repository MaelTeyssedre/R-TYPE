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

            /**
             * \fn void operator()(Registry &r, SparseArray<components::myTime_s> &times)
             *
             * \brief To be used by the ECS
             * 
             * \param r A reference to the registry
             * 
             * \param times a reference to a sparceArray of time components
             */
            void operator()(Registry &r, SparseArray<components::myTime_s> &times);
        private:
            std::chrono::nanoseconds _currentDeltaTime; /*! The current delta time*/
    };

#endif /* !UPDATETIME_HPP_ */