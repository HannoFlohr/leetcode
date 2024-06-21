class Solution {
private:
    int countPrimes(int n) {
        vector<bool> isPrime (n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int p = 2; p <= n; ++p) {
            if(isPrime[p]) {
                for(int i = p*p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        return accumulate(isPrime.begin(), isPrime.end(), 0);
    }

public:
    int numPrimeArrangements(int n) {
        const unsigned int MOD = 1e9+7;
        int prime_count = countPrimes(n);
        int non_prime_count = n - prime_count;
        long long arrangements = 1;

        while(prime_count > 0) {
            arrangements = (arrangements * prime_count--) % MOD;
        }
        while(non_prime_count > 0) {
            arrangements = (arrangements * non_prime_count--) % MOD;
        }
  
        return arrangements;
    }
};
//https://leetcode.com/problems/prime-arrangements/