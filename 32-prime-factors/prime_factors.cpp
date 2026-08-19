#include "prime_factors.h"

namespace prime_factors {

// TODO: add your solution here

std::vector<long long> of(long long num) {
    std::vector<long long> factors{};
    long long i{2};
    while (num > 1) {
        if (i * i > num) {
            factors.emplace_back(num);
            break;
        }
        if (num % i == 0) {
            factors.emplace_back(i);
            num /= i;
        } else {
            ++i;
        }
    }
    return factors;
}

}  // namespace prime_factors
