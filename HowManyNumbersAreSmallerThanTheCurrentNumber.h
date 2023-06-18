class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> frequency (101); //0 <= nums[i] <= 100
        for(const auto& n : nums)
            frequency[n]++;

        vector<int> smallerThanX (101);
        for(int i = 1; i < 101; i++) 
            smallerThanX[i] = smallerThanX[i-1] + frequency[i-1];

        vector<int> result (nums.size());
        for(int i = 0; i < nums.size(); ++i)
            result[i] = smallerThanX[ nums[i] ];

        return result;
    }
};
//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/