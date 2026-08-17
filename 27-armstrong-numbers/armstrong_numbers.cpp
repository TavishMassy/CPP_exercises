#include "armstrong_numbers.h"

namespace armstrong_numbers {

// TODO: add your solution here
bool is_armstrong_number(int num) {
    int original_num{num};
    int armstrong_num{0};
    int power_num{static_cast<int>(std::to_string(num).length())};
    while(num > 0) {
        armstrong_num += std::pow(num % 10, power_num);
        num /= 10;
    }
    if (original_num == armstrong_num) {
        return true;
    }
    return false;
}

}  // namespace armstrong_numbers
