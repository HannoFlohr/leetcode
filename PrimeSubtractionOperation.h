class Solution {
private:
    void getPrimes(vector<int>& primes, int limit) {
        //use sieve of eratosthenes for primes
        vector<bool> isPrime (limit, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i < limit; ++i) {
            if(!isPrime[i])
                continue;
            for(int x = i*i; x < limit; x += i) 
                isPrime[x] = false;
        }
        //extract primes
        for(int i = 0; i < limit; ++i) {
            if(isPrime[i])
                primes.push_back(i);
        }
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        //get primes up to 1000 using sieve 
        vector<int> primes;
        getPrimes(primes, 1001);
        
        int n = nums.size(), p = primes.size(), upperLimit = nums.back();
        for(int i = n-2; i >= 0; --i) {
            //skip if number already smaller than number at the larger index
            if(nums[i] < upperLimit) {
                upperLimit = nums[i];
                continue;
            }
            
            //find prime to make nums[i-1] < nums[i] < nums[i+1]
            bool primeFound = false;
            for(int j = 0; j < p && primes[j] < nums[i]; ++j) {
                if(nums[i] - primes[j] < upperLimit) {
                    upperLimit = nums[i] - primes[j];
                    primeFound = true;
                    break;
                }
            }
            //if no such prime exists, nums cant be made strictly increasing
            if(!primeFound)
                return false;
        }
        
        return true;
    }
};
//https://leetcode.com/problems/prime-subtraction-operation/