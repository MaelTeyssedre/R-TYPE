/**
 * \file UpdatePosition.hpp
 *
 * \brief file where the update position system is defined
 */

#ifndef UPDATEPOSITION_HPP_
    #define UPDATEPOSITION_HPP_

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
         * \class UpdatePosition UpdatePosition.hpp 
         * 
         * \brief class that contain the system UpdatePosition
         */
        class UpdatePosition {
            public:
                /**
                 * \fn explicit UpdatePosition() = default
                 *
                 * \brief ctor UpdatePosition
                 */
                explicit UpdatePosition() = default;

                /**
                 * \fn virtual ~UpdatePosition() = default
                 *
                 * \brief dtor UpdatePosition
                 */
                virtual ~UpdatePosition() = default;

                /**
                 * \fn  void operator()(Registry &r, SparseArray<components::position_s> &positions, SparseArray<components::direction_s> &directions, SparseArray<components::velocity_s> &velocities)
                 *
                 * \brief operator to be used by the ECS
                 * 
                 * \param r A reference to the registry
                 * 
                 * \param positions reference to a sparseArray of position components
                 * 
                 * \param directions reference to a sparseArray of direction components
                 * 
                 * \param velocities reference to a sparseArray of velocity components
                 */
                void operator()(Registry &r, SparseArray<components::position_s> &positions, SparseArray<components::direction_s> &directions, SparseArray<components::velocity_s> &velocities);
        };
    }

#endif /* !UPDATEPOSITION_HPP_ */
