#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
bool connection_check(speedywagon::pillar_men_sensor* intel) {
    if (intel != nullptr) {
        return true;
    }
    return false;
}

int activity_counter(speedywagon::pillar_men_sensor intel[], int capacity) {
    int total_activity{0};
    if (connection_check(intel)) {
        for (int i{0}; i < capacity; i++) {
            total_activity += intel[i].activity;
        }
    }
    return total_activity;
}

bool alarm_control(speedywagon::pillar_men_sensor* intel) {
    if (connection_check(intel)) {
        if (intel->activity > 0) {
            return true;
        }
    }
    return false;
}

bool uv_alarm(speedywagon::pillar_men_sensor* intel) {
    if (connection_check(intel)) {
        if (intel->activity == 0) {
            return true;
        }
    }
    return false;
}

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
