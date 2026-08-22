#include "power_of_troy.h"

namespace troy {

void give_new_artifact(human& person, std::string name) {
    person.possession = std::make_unique<artifact>(std::move(name));
}

void exchange_artifacts(std::unique_ptr<artifact>& item1, std::unique_ptr<artifact>& item2) {
    std::swap(item1, item2);
}

void manifest_power(human& person, std::string name) {
    person.own_power = std::make_unique<power>(std::move(name));
}

void use_power(human& person1, human& person2) {
    person2.influenced_by = person1.own_power;
}

long power_intensity(human& person) {
    return person.own_power.use_count();
}

}  // namespace troy
