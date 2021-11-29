
#include "UpdatePosition.hpp"

void rtype::UpdatePosition::operator()(Registry &r, SparseArray<rtype::components::position_s> &positions, SparseArray<rtype::components::direction_s> &directions, SparseArray<rtype::components::velocity_s> &velocities)
{
    (void)r;
    for (size_t i = 0; i < positions.size(); i++) {
        auto &pos = positions[i];
        auto &dir = directions[i];
        auto &vel = velocities[i];
        if (!(pos && dir && vel))
            continue;
        pos.value().x += vel.value().x * dir.value().x;
        pos.value().y += vel.value().y * dir.value().y;
    }
}
