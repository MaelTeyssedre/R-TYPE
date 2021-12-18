
#include "UpdatePosition.hpp"
#include "Zipper.hpp"

void rtype::UpdatePosition::operator()(Registry& r, SparseArray<components::position_s>& positions, SparseArray<components::direction_s>& directions, SparseArray<components::velocity_t>& velocities)
{
	(void)r;
	for (auto&& [pos, dir, vel] : Zipper(positions, directions, velocities)) {
		pos.x += vel.x * dir.x;
		pos.y += vel.y * dir.y;
	}
}
