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
    #include "Zipper.hpp"
    #include "Components.hpp"

    namespace rtype {
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
                 * \fn auto operator()(Registry &r, SparseArray<rtype::components::myTime_s> &times) -> void
                 *
                 * \brief operator to be used by the ECS
                 * 
                 * \param r A reference to the registry
                 * 
                 * \param times reference to a sparseArray of times components
                 */
                auto operator()(Registry &r, SparseArray<rtype::components::myTime_s> &times) -> void;
            private:
                std::chrono::nanoseconds _currentDeltaTime; /*! The current delta time*/
        };
    }

#endif /* !UPDATETIME_HPP_ */
