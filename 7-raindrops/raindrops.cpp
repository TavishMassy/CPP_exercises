#include "raindrops.h"

namespace raindrops {

// TODO: add your solution here
    std::string convert(int num) {
        std::string word;
        if(num % 3 == 0) {
            word += "Pling";
        } if(num % 5 == 0) {
            word += "Plang";
        } if(num % 7 == 0) {
            word += "Plong";
        } if(word == "") {
            word = std::to_string(num);
        }
        return word;
    }
}  // namespace raindrops
