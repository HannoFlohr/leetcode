class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        const int MAX_NUM = 100;
        vector<int> numbers (MAX_NUM+1, 0);
        for(const auto& num : nums) 
            numbers[num]++;

        int count = 0;
        for(int i=0; i<=MAX_NUM-k; i++) 
            if(numbers[i] > 0 && numbers[i+k] > 0)
                count += (numbers[i] * numbers[i+k]);
        
        return count;
    }
};
//https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/