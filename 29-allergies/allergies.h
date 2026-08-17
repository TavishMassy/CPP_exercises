#pragma once
#include <string>
#include <vector>
#include <unordered_set>

namespace allergies {

// TODO: add your solution here
class allergy_test {
    public:
        allergy_test(int score);
        bool is_allergic_to(std::string allergie);
        std::unordered_set<std::string> get_allergies();
    private:
        int score;
        std::unordered_set<std::string> allergies_found{};
        const std::vector<std::string> allergie_names{
            "eggs",
            "peanuts",
            "shellfish",
            "strawberries",
            "tomatoes",
            "chocolate",
            "pollen",
            "cats"
        };
        const std::vector<int> allergie_scores{
            1,
            2,
            4,
            8,
            16,
            32,
            64,
            128
        };
};

}  // namespace allergies
