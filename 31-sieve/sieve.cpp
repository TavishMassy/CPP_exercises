#include "sieve.h"

namespace sieve {

// TODO: add your solution here

std::vector<int> primes(int till) {
    if (till < 2) {
        return {};
    }
    std::vector<bool> is_prime(till + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p <= till; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= till; i += p) {
                is_prime[i] = false;
            }
        }
    }
    std::vector<int> prime_nums;
    for (int p = 2; p <= till; ++p) {
        if (is_prime[p]) {
            prime_nums.push_back(p);
        }
    }
    return prime_nums;
}

}  // namespace sieve