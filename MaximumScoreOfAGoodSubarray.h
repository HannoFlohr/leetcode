class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int max_score = nums[k], i = k, j = k, min_i = nums[k], n = nums.size();

        while(i > 0 || j < n-1) {
            if(i == 0)
                j++;
            else if(j == n-1) 
                i--;
            else if(nums[i-1] < nums[j+1])
                j++;
            else
                i--;

            min_i = min(min_i, min(nums[i], nums[j]));
            max_score = max(max_score, min_i * (j-i+1));
        }

        return max_score;
    }
};
//https://leetcode.com/problems/maximum-score-of-a-good-subarray/