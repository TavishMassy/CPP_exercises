#pragma once
#include <vector>
#include <string>
namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string> layers, int time = 2);
amount quantities(std::vector<std::string> layers);
void addSecretIngredient(std::vector<std::string>& layers1, std::string ingredient);
void addSecretIngredient(std::vector<std::string>& layers1, std::vector<std::string> layers2);
std::vector<double> scaleRecipe(std::vector<double> quantities, int portions);

}  // namespace lasagna_master
