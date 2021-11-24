#include "UpdateTime.hpp"

void UpdateTime::operator()(Registry &r, SparseArray<components::myTime_t> &times) {
    (void)r;
    static std::chrono::steady_clock::time_point lastTick = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point currentTick = std::chrono::steady_clock::now();
    std::optional<components::myTime_t> &time = times[RESERVED_TIME_INDEX];
    if (time)
        time.value().deltaTime = (currentTick - lastTick);
    lastTick = currentTick;
}
