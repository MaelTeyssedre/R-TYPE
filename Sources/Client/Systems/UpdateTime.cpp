#include "UpdateTime.hpp"

void UpdateTime::operator()(Registry &r, SparseArray<components::time_s> &times) {
    static std::chrono::steady_clock::time_point lastTick = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point currentTick = std::chrono::steady_clock::now();
    std::optional<components::time_s> &time = times[RESERVED_TIME_INDEX];
    if (time)
        time.value().deltaTime = (currentTick - lastTick);
    lastTick = currentTick;
}
