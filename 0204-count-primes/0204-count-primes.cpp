class Solution {
public:
    int countPrimes(int n) {
        // Edge cases: there are no primes strictly less than 2
        if (n <= 2) return 0;

        // Vector to store primality. 
        // We only track odd numbers, so we need a size of n/2.
        // isPrime[i] will represent the number (2 * i + 1).
        vector<bool> isPrime(n / 2, true);
        
        // Start count at 1 because we manually include the prime number 2
        int count = 1; 

        // Sieve loop: only process odd numbers up to sqrt(n)
        for (int i = 3; i * i < n; i += 2) {
            // Mapping real number 'i' to its vector index: index = (i - 1) / 2
            if (isPrime[i / 2]) {
                // Mark multiples of i, starting from i * i, skipping even multiples
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j / 2] = false;
                }
            }
        }

        // Count all remaining marked true values (representing odd primes)
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i / 2]) {
                count++;
            }
        }

        return count;
    }
};
