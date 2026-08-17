#include "allergies.h"

namespace allergies {

// TODO: add your solution here
allergy_test::allergy_test(int score) {
    for (size_t i{0}; i < allergie_scores.size(); ++i) {
        if (score & allergie_scores.at(i)) {
            allergies_found.insert(allergie_names.at(i));
        } 
    }
}
bool allergy_test::is_allergic_to(std::string allergie) {
    return allergies_found.count(allergie) > 0;
}
std::unordered_set<std::string> allergy_test::get_allergies() {
    return allergies_found;
}

}  // namespace allergies
