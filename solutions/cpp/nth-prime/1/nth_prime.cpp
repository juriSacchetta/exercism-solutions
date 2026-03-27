#include "nth_prime.h"
#include <vector>
#include <cmath>
#include <stdexcept>

namespace nth_prime {

    int nth(int n) {
        if (n <= 0) throw std::domain_error("n must be positive");
        std::vector<int> primes;
        primes.reserve(n);
        int candidate = 2;
        
        while(static_cast<int>(primes.size()) < n){
            const int limit = static_cast<int>(std::sqrt(candidate));
            int j = 2; 
            for(; j <= limit; ++j){
                if(candidate % j==0) break;
            }
            if(j > limit) primes.push_back(candidate);
            candidate += (candidate == 2 ? 1 : 2);
        }
        return primes.back();
    }

}  // namespace nth_prime
