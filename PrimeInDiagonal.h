//using sieve: (5.19% | 5%) 
class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        const int N = nums.size();
        const int MAXP = 4 * 1e6;
        vector<bool> prime (MAXP+1,true);
        prime[0] = false, prime[1] = false;
        for(int p = 2; p*p <= MAXP; ++p) 
            if(prime[p] == true) 
                for(int i = p*p; i <= MAXP; i += p) 
                    prime[i] = false;

        int max_prime = 0;
        for(int i = 0; i < N; i++) {
            if(prime[nums[i][i]])
                max_prime = max(max_prime, nums[i][i]);
            if(prime[nums[i][N-1-i]])
                max_prime = max(max_prime, nums[i][N-1-i]);
        }

        return max_prime;
    }
};
https://leetcode.com/problems/prime-in-diagonal/

//using another function to see if number is prime (49.98% | 39.87%) 
class Solution {
private:
    bool isPrime(int n) {
        if(n <= 2 || n%2 == 0) 
            return n == 2;
        
        for(int i = 3; i*i <= n; i += 2)
            if(n%i == 0)
                return false;

        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        const int N = nums.size();
        int max_prime = 0;

        for(int i = 0; i < N; i++) {
            if(isPrime(nums[i][i]))
                max_prime = max(max_prime, nums[i][i]);
            if(isPrime(nums[i][N-1-i]))
                max_prime = max(max_prime, nums[i][N-1-i]);
        }

        return max_prime;
    }
};

//make set of numbers in diagonals, reverse iterate to find max prime (40.61% | 14.30%) 
class Solution {
private:
    bool isPrime(int n) {
        if(n <= 2 || n%2 == 0) 
            return n == 2;
        
        for(int i = 3; i*i <= n; i += 2)
            if(n%i == 0)
                return false;

        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        const int N = nums.size();
        set<int> diagonals;

        for(int i = 0; i < N; i++) {
            diagonals.insert(nums[i][i]);
            diagonals.insert(nums[i][N-1-i]);
        }

        for(auto x = diagonals.rbegin(); x != diagonals.rend(); ++x)
            if(isPrime(*x))
                return *x;

        return 0;
    }
};