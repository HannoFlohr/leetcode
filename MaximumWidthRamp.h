class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int max_width = 0, n = nums.size();
        vector<int> v = {0};

        //push elements on stack in decreasing order; nums[i] < back of stack
        for(int i = 1; nums[v.back()] > nums[n-1]; ++i) {
            if(nums[v.back()] > nums[i])
                v.push_back(i);
        }

        //from right to left: pop all elements of the stack that are smaller and compare width of ramp
        for(int i = n-1; i > max_width; --i) {
            while(!v.empty() && nums[v.back()] <= nums[i]) {
                max_width = max(max_width, i - v.back());
                v.pop_back();
            }
        }

        return max_width;  
    }
};
//https://leetcode.com/problems/maximum-width-ramp/