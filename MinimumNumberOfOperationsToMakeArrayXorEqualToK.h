class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return bitset<20>(accumulate(nums.begin(), nums.end(), k, bit_xor<>())).count();
    }
};
//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

/* steps done before 1-liner 

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(int n : nums) {
            k ^= n;
        }
        bitset<20> bits_k {(unsigned long long)k};
        return bits_k.count();
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for(int n : nums) {
            x ^= n;
        }
        
        bitset<20> bits_x {(unsigned long long)x};
        bitset<20> bits_k {(unsigned long long)k};

        int count = 0;
        for(int i = 0; i < bits_x.size(); ++i) {
            if(bits_x[i] != bits_k[i]) {
                ++count;
            }
        }

        return count;
    }
};
*/