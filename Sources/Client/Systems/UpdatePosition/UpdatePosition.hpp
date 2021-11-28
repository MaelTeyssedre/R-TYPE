/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** UpdatePosition
*/

#ifndef UPDATEPOSITION_HPP_
    #define UPDATEPOSITION_HPP_

    #include "Registry.hpp"
    #include "Components.hpp"

    namespace rtype {
        class UpdatePosition {
            public:
                explicit UpdatePosition() = default;
                virtual ~UpdatePosition() = default;

                void operator()(Registry &r, SparseArray<components::position_s> &positions, SparseArray<components::direction_s> &directions, SparseArray<components::velocity_s> &velocities);
        };
    }

#endif /* !UPDATEPOSITION_HPP_ */
