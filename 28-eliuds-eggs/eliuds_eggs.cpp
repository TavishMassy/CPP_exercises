#include "eliuds_eggs.h"

namespace chicken_coop {

// TODO: add your solution here
int positions_to_quantity(int num) {
    int total_eggs{0};
    while (num > 0) {
        if (num % 2 != 0) {
            --num;
            ++total_eggs;
        }
        num /= 2;
    }
    return total_eggs;
}

}  // namespace chicken_coop
