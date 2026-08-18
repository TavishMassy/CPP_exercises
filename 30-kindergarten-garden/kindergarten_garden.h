#pragma once
#include <string>
#include <vector>
#include <array>

namespace kindergarten_garden {

// TODO: add your solution here
enum Plants{
    clover = 'C',
    grass = 'G',
    violets = 'V',
    radishes = 'R'
};

const std::array<std::string, 24> kids{
    "Alice", "Bob", "Charlie", 
    "David", "Eve", "Fred", 
    "Ginny", "Harriet", "Ileana", 
    "Joseph", "Kincaid", "Larry"
};

std::array<kindergarten_garden::Plants, 4> plants(std::string sequence, std::string name);
Plants _find_enum(char& c);

}  // namespace kindergarten_garden
