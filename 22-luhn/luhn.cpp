#include "luhn.h"

namespace luhn {

// TODO: add your solution here
bool valid(const std::string& card_num) {
    int sum{0};
    int num{0};
    int count{0};
    bool is_even{false};
    char c;
    int length{static_cast<int>(card_num.size())};
    for (int i{0}; i < length; i++) {
        c = card_num.at(length - 1 - i);
        if (isspace(c)) {
            continue;
        }
        if (c >= '0' && c <= '9') {
            num = c - '0';
            if (is_even) {
                num *= 2;
                if (num > 9) {
                    num -= 9;
                }
                sum += num;
                is_even = false;
            } else {
                sum += num;
                is_even = true;
            }
            count++;
        } else {
            return false;
        }
    }
    if (sum % 10 == 0 && count > 1) {
        return true;
    }
    return false;
}

}  // namespace luhn
