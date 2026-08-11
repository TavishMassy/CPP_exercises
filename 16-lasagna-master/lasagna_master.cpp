#include "lasagna_master.h"

namespace lasagna_master {

// TODO: add your solution here
int preparationTime(std::vector<std::string> layers, int time) {
    return layers.size() * time;
}

amount quantities(std::vector<std::string> layers) {
    amount amount{0, 0.0};
    for (std::string layer : layers) {
        if (layer == "sauce") {
            amount.sauce += 0.2;
        }
        if (layer == "noodles") {
            amount.noodles += 50;
        }
    }
    return amount;
}

void addSecretIngredient(std::vector<std::string>& layers1, std::string ingredient) {
    for (std::string& layer : layers1) {
        if (layer == "?") {
            layer = ingredient;
        }
    }
}

void addSecretIngredient(std::vector<std::string>& layers1, std::vector<std::string> layers2) {
    int i{1};
    for (std::string& layer : layers1) {
        if (layer == "?") {
            layer = layers2.at(layers2.size() - (i % layers2.size()));
            i++;
        }
    }
}

std::vector<double> scaleRecipe(std::vector<double> quantities, int portions) {
    for (double& qty : quantities) {
        qty *= portions/2.0;
    }
    return quantities;
}

}  // namespace lasagna_master
