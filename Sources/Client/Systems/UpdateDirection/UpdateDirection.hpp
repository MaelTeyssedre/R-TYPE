/**
 * \file UpdateDirection.hpp
 *
 * \brief file where the update direction system is defined
 */

#ifndef UPDATEDIRECTION_HPP_
    #define UPDATEDIRECTION_HPP_

    #include "Registry.hpp"
    #include "Components.hpp"

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {
        /**
         * \class UpdateDirection UpdateDirection.hpp 
         * 
         * \brief class that contain the system UpdateDirection
         */
        class UpdateDirection {
            public:
                /**
                 * \fn explicit UpdateDirection() = default
                 *
                 * \brief ctor UpdateDirection
                 */
                explicit UpdateDirection() = default;

                /**
                 * \fn virtual ~UpdateDirection() = default
                 *
                 * \brief dtor UpdateDirection
                 */
                virtual ~UpdateDirection() = default;

                /**
                 * \fn auto operator()(Registry &r, SparseArray<components::direction_s> &directions, SparseArray<components::keyState_s> &keys) -> void
                 *
                 * \brief operator to be used by the ECS
                 * 
                 * \param r A reference to the registry
                 * 
                 * \param directions reference to a sparseArray of direction components
                 *
                 * \param keys reference to a sparseArray of key components
                 */
                auto operator()(Registry &r, SparseArray<components::direction_s> &directions, SparseArray<components::keyState_s> &keys) -> void;
        };
    }

#endif /* !UPDATEDIRECTION_HPP_ */
