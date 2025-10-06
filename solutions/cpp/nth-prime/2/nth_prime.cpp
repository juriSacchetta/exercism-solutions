#include "nth_prime.h"
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>

namespace nth_prime {

int nth(int n) {
    if (n <= 0) throw std::domain_error("n must be positive");

    int limit;
    if (n<6) {
        limit = 15;
    } else {
        const double dn = static_cast<double>(n);
        const double bound = dn * (std::log(dn) + std::log(std::log(dn)));
        limit = static_cast<int>(bound + 10 * dn);
    }

    std::vector<bool> sieve(static_cast<size_t>(limit) + 1, true);
    sieve[0] = sieve[1] = false;

    for(int p=2; p * p < limit; ++p){
        if (!sieve[p]) continue;
        for (int m = p * p; m <= limit; m += p) {
            sieve[m] = false;
        }
    }
    
    int count = 0;
    for (int i = 2; i <= limit; ++i) {
        if (sieve[i] && ++count == n) return i;
    }
    
    throw std::domain_error("upper bound insufficient for nth prime");
}

}  // namespace nth_prime
