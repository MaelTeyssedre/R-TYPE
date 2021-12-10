
#include "UpdateDirection.hpp"

void rtype::UpdateDirection::operator()(Registry &r, SparseArray<rtype::components::direction_t> &directions, SparseArray<rtype::components::keyState_t> &keys)
{
    (void)r;
    for (size_t i = 0; i < directions.size() && i < keys.size(); i++) {
        auto &dir = directions[i];
        auto &key = keys[i];
        if (!(dir && key))
            continue;
        if (key.value().keyRight) {
            dir.value().x = 1;
            dir.value().y = 0;
        }
        if (key.value().keyLeft) {
            dir.value().x = -1;
            dir.value().y = 0;
        }
        if (key.value().keyDown) {
            dir.value().x = 0;
            dir.value().y = 1;
        }
        if (key.value().keyUp) {
            dir.value().x = 0;
            dir.value().y = -1;
        }
        if (key.value().keyDown && key.value().keyRight) {
            dir.value().x = 1;
            dir.value().y = 1;
        }
        if (key.value().keyDown && key.value().keyLeft) {
            dir.value().y = 1;
            dir.value().x = -1;
        }
        if (key.value().keyLeft && key.value().keyUp) {
            dir.value().x = 1;
            dir.value().y = -1;
        }
        if (key.value().keyUp && key.value().keyLeft) {
            dir.value().x = -1;
            dir.value().y = -1;
        }
        if ((key.value().keyUp && key.value().keyDown) || (key.value().keyLeft && key.value().keyRight) || (key.value().keyDown && key.value().keyLeft && key.value().keyRight && key.value().keyUp)) {
            dir.value().x = 0;
            dir.value().y = 0;
        }
    }

}
