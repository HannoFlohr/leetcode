class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> ugly_numbers (n, INT_MAX);
        ugly_numbers[0] = 1;
        vector<int> multipliers (primes.size(), 0);

        for(int i=1; i<n; i++) {
            for(int p=0; p<primes.size(); p++)
                ugly_numbers[i] = min(ugly_numbers[i], ugly_numbers[multipliers[p]] * primes[p]);
            for(int p=0; p<primes.size(); p++) 
                if(ugly_numbers[i] == ugly_numbers[multipliers[p]] * primes[p])
                    multipliers[p]++;
        }

        return ugly_numbers[n-1];
    }
};
//https://leetcode.com/problems/super-ugly-number/