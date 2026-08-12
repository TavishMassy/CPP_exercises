#include "protein_translation.h"

namespace protein_translation {

// TODO: add your solution here
std::vector<std::string> proteins(std::string sequence) {
    std::vector<std::string> found;
    std::string amino_acid;
    for (size_t i{0}; i < sequence.length() / 3; i++) {
        for (size_t j{0}; j < amino_acids.size(); j++) {
            amino_acid = amino_acids[j];
            for (std::string colon : colons[j]) {
                if (colon == sequence.substr(i*3, 3)) {
                    if (amino_acid == "STOP") {
                        return found;
                    }
                    found.emplace_back(amino_acid);
                }
            }
        }
    }
    return found;
}

}  // namespace protein_translation
