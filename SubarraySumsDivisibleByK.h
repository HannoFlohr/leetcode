class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0, sum = 0, remainder;
        vector<int> freq (k, 0); // frequency of remainders %k
        freq[0] = 1; //needed for increment at first encounter of remainder 0

        for(const auto &num : nums) {
            sum += num;

            remainder = sum % k;
            if(remainder < 0) //choose positive remainder
                remainder += k;

            result += freq[remainder];
            freq[remainder]++;
        }

        return result;
    }
};
//https://leetcode.com/problems/subarray-sums-divisible-by-k/