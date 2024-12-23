class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int n = nums.size();
        vector<int> lower_before (n, 1), lower_after(n, 1);
    
        //for each index count numbers that are lower before current index
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) 
                    lower_before[i] = max(lower_before[i], lower_before[j] + 1);
            }
        }    
        //for each index count number that are lower after current index
        for(int i = n-1; i >= 0; --i) {
            for(int j = n-1; j > i; --j) {
                if(nums[j] < nums[i])
                    lower_after[i] = max(lower_after[i], lower_after[j] + 1);
            }
        }
    
        //find maximum mountain length
        int max_length = 0;
        for(int i = 1; i < n-1; ++i) {
            if(lower_before[i] > 1 && lower_after[i] > 1)
                max_length = max(max_length, lower_before[i] + lower_after[i] - 1);
        }

        return n - max_length;
    }
};
//https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/