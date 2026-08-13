#include "trinary.h"

namespace trinary {

// TODO: add your solution here
int to_decimal(const std::string& num) {
    int decimal = 0;
    for (char c : num) {
        if (c < '0' || c > '2') return 0;  
        decimal = decimal * 3 + (c - '0');
    }   
    return decimal;
}


}  // namespace trinary
