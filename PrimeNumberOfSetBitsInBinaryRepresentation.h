class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        const set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

        int count = 0;
        for(int n = left; n <= right; n++) {
            if(primes.contains( bitset<20>(n).count() )) {
                count++;
            }
        }

        return count;
    }
};
//https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/