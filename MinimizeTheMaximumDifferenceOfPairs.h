class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), left = 0, right = nums[n-1] - nums[0], mid, pairs;

        while(left < right) {
            mid = (left + right) / 2;
            pairs = 0;

            for(int i = 1; i < n && pairs < p; ++i) 
                if(nums[i] - nums[i-1] <= mid) 
                    ++pairs, ++i;

            if(pairs >= p) 
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
//https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/