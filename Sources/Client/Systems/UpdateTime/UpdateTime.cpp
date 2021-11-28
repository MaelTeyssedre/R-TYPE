#include "UpdateTime.hpp"

void rtype::UpdateTime::operator()(Registry &r, SparseArray<components::myTime_s> &times) {
    (void)r;
    static std::chrono::steady_clock::time_point lastTick = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point currentTick = std::chrono::steady_clock::now();
    // for (auto &&[time] : Zipper(times)) {
    //     time.deltaTime = (currentTick - lastTick);
    // }
    std::optional<components::myTime_s> &time = times[rtype::constants::RESERVED_ID::TIME_UPDATE];
    if (time) {
        time.value().deltaTime = (currentTick - lastTick);
    }
    lastTick = currentTick;
}
