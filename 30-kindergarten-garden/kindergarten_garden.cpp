#include "kindergarten_garden.h"

namespace kindergarten_garden {

// TODO: add your solution here
std::array<Plants, 4> plants(std::string sequence, std::string name) {
    int index{2};
    int length{static_cast<int>(sequence.length())};
    for (int i{0}; i < static_cast<int>(kids.size()); ++i) {
        if (name == kids.at(i)) {
            index *= i;
            break;
        }
    }
    char r1c1(sequence.at(index));
    char r1c2(sequence.at((index) + 1));
    char r2c1(sequence.at((length / 2) + 1 + (index)));
    char r2c2(sequence.at((length / 2) + 2 + (index)));
    return std::array<Plants, 4> {_find_enum(r1c1), _find_enum(r1c2), 
                                  _find_enum(r2c1), _find_enum(r2c2)};
}

Plants _find_enum(char& c) {
    return static_cast<Plants>(c);
}

}  // namespace kindergarten_garden
