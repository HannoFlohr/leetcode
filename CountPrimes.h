class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime (n+1, true);
        for(int p=2; p*p<=n; p++)
            if(prime[p])
                for(int i=p*p; i<=n; i+=p)
                    prime[i] = false;
        
        int primes = 0;
        for(int p=2; p<n; p++)
            if(prime[p])
                primes++;
        
        return primes;
    }
};
//https://leetcode.com/problems/count-primes/