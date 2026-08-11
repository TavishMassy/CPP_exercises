#pragma once

#include <string>
#include <vector>

namespace speedywagon {

struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};
bool connection_check(speedywagon::pillar_men_sensor* intel);
int activity_counter(speedywagon::pillar_men_sensor intel[], int capacity);
bool alarm_control(speedywagon::pillar_men_sensor* intel);
bool uv_alarm(speedywagon::pillar_men_sensor* intel);

int uv_light_heuristic(std::vector<int>* data_array);

}  // namespace speedywagon
