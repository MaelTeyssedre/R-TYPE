
#include "UpdatePosition.hpp"
#include "Zipper.hpp"

void rtype::UpdatePosition::operator()(Registry &r, SparseArray<rtype::components::position_s> &positions, SparseArray<rtype::components::direction_s> &directions, SparseArray<rtype::components::velocity_t> &velocities)
{
    (void)r;
    for (auto&& [pos, dir, vel] : Zipper(positions, directions, velocities)) {
        pos.x += vel.x * dir.x;
        pos.y += vel.y * dir.y;
    }
}
