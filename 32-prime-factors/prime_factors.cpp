#include "prime_factors.h"

namespace prime_factors {

// TODO: add your solution here

std::vector<long long> of(long long num) {
    std::vector<long long> factors{};
    long long srqt_mid{static_cast<long long>(ceil(sqrt(num * 1.0)))};
    if (srqt_mid > prime_nums.back()) {
        _primes(srqt_mid);
    }
    int i{0};
    while (num > 1) {
        if (i >= static_cast<int>(prime_nums.size())) {
            factors.emplace_back(num);
            break;
        }
        long long prime_num = prime_nums.at(i);
        if (num % prime_num == 0) {
            factors.emplace_back(prime_num);
            num /= prime_num;
        } else {
            ++i;
        }
    }
    return factors;
}

void _primes(long long& till) {
    bool found_prime = true;
    int i{1};
    while (prime_nums.back() < till) {
        for (long long& prime_num : prime_nums) {
            if ((prime_nums.back() + i) % prime_num == 0) {
                ++i;
                found_prime = false;
                break;
            }
        }
        if (found_prime) {
            prime_nums.emplace_back(prime_nums.back() + i);
            i = 1;
        }
        found_prime = true;
    }
}

}  // namespace prime_factors
